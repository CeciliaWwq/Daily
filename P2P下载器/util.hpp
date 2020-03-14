#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<boost/filesystem.hpp>
#ifdef _WIN32
//windows头文件
#include<ws2tcpip.h>
#include<iphlpapi.h> //获取网卡信息的头文件
#pragma comment(lib,"Iphlpapi.lib")//获取网卡信息接口的库文件
#pragma comment(lib,"ws2_32.lib")//windows下的socket库
#else
//linux头文件
#endif
class StringUtil
{
public:
	static int64_t Str2Dig(const std::string& num) {
		std::stringstream tmp;
		tmp << num;
		int64_t res;
		tmp >> res;
		return res;
	}
};
class FileUtil
{
public:
	static int64_t GetFileSize(const std::string& name)
	{
		return boost::filesystem::file_size(name);
	}
	static bool Write(const std::string& name, const std::string& body, int64_t offset = 0)//最大偏移量需要小于4G
	{
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "wb+");
		if (fp == NULL) {
			std::cerr << "打开文件失败\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fwrite(body.c_str(), 1, body.size(), fp);
		if (ret != body.size())
		{
			std::cerr << "向文件写入数据失败\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
	}
		/*
		std::ofstream ofs(name);
		if (ofs.is_open() == false)
		{
			std::cerr << "打开文件失败\n" ;
				return false;
		}
		ofs.seekp(offset, std::ios::beg);//读写位置跳转到相对文件起始位置开始偏移的offset偏移量
		ofs.write(&body[0], body.size());
		if (ofs.good() == false) {
			std::cerr << "向文件写入数据失败\n";
			   ofs.close();
				return false;
		}
		ofs.close();
		return true;
	}
	*/

	//指针参数表示这是一个输出型参数
	//const & 表示这是一个输入型参数
	//& 表示这是一个输入输出型参数
	//(输入输出仅仅对自己是主体，向文件中读取数据是ifstream,向文件中写出数据是ofstream)
	static bool Read(const std::string& name, std::string* body) {
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		std::cout << "读取文件数据：" << name << "size:" << filesize << "\n";
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "rb+");
		if (fp == NULL)
		{
			std::cerr << "打开文件失败\n";
			return false;
		}
		int ret = fread(&(*body)[0], 1, filesize, fp);
		if (ret != filesize) {
			std::cerr << "从文件读取数据失败\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
#if 0
		std::ifstream ifs(name);
		if (ifs.is_open() == false)
		{
			std::cerr << "打开文件失败\n";
				return false;
		}
		int64_t filesize = boost::filesystem::file_size(name);//通过文件名获取文件大小
		body->resize(filesize);
		std::cout << "要读取的文件大小：" << name << ":" << filesize << std::endl;
		ifs.read(&(*body)[0], filesize);
#endif
		/*
		if (ifs.good() == false)
		{
			std::cerr << "读取文件数据失败\n";
			std::cout << *body << std::endl;
			ifs.close();
			return false;
		}
		ifs.close();
		return true;
		*/
		   
	}
	static bool ReadRange(const std::string& name, std::string* body, int64_t len, int64_t offset)
	{
		body->resize(len);
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "rb+");
		if (fp == NULL)
		{
			std::cerr << "打开文件失败\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1,len, fp);
		if (ret != len) {
			std::cerr << "从文件读取数据失败\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
	}
};
class Adapter
{
public:
	uint32_t _ip_addr;//网卡的IP地址
	uint32_t _mask_addr;//网卡的子网掩码
};

class AdapterUtil
{
public:
#ifdef _WIN32
	//windows下获取网卡信息实现
	static bool GetAllAdapter(std::vector<Adapter>* list) {
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
		//GetAdapterInfo win下获取网卡信息的接口
		//网卡信息可能有多个，因此传入一个指针

		//获取网卡信息有可能会失败，因为空间不足，
		//因此传入的是一个输出型参数用来为用户返回所有网卡信息空间占用大小
		uint64_t all_adapter_size = sizeof(IP_ADAPTER_INFO);
		//all_adapter_size用于获取实际所有网卡信息所占用的空间大小
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
			if (ret == ERROR_BUFFER_OVERFLOW) {
				//这个错误表示缓冲区空间不足
				//重新给指针申请空间
				delete p_adapters;
				p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
				GetAdaptersInfo(p_adapters, (PULONG)& all_adapter_size);//重新获取网卡信息
		}
			while (p_adapters) {
				Adapter adapter;
				inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String,&adapter._ip_addr);
				inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._mask_addr);
				//inet_pton(int family,char* string,void* buf)
			    //将一个字符串点分十进制的IP地址转换为网络字节序IP地址
				//family:AF_INET使用IPV4地址结构
				//string:自符串点分十进制的IP地址
				//buf:一块缓冲区，用于接收转换后的网络字节序
				//adapter._ip_addr=inet_addr(p_adapters->IpAddressList.IpAddress.String);
				//adapter._mask_addr=inet_addr(p_adapters->IpAddressList.IpMask.String);
				if (adapter._ip_addr != 0) {//因为有些网卡并没有启用，导致ip地址为0
                    list->push_back(adapter);//将网卡信息添加到vector返回给用户
					std::cout << "网卡名称:" << p_adapters->AdapterName << std::endl;
					std::cout << "网卡描述：" << p_adapters->Description << std::endl;
					std::cout << "IP地址：" << p_adapters->IpAddressList.IpAddress.String << std::endl;
					std::cout << "子网掩码：" << p_adapters->IpAddressList.IpMask.String << std::endl;
					std::cout << std::endl;
				}
				p_adapters = p_adapters->Next;
		}
			delete p_adapters;
		return true;
	}
#else
	//Linux下获取网卡信息的实现
	bool GetAllAdapter(std::vector<Adapter>* list);
#endif
};