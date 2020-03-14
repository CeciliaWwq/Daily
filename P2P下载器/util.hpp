#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<boost/filesystem.hpp>
#ifdef _WIN32
//windowsͷ�ļ�
#include<ws2tcpip.h>
#include<iphlpapi.h> //��ȡ������Ϣ��ͷ�ļ�
#pragma comment(lib,"Iphlpapi.lib")//��ȡ������Ϣ�ӿڵĿ��ļ�
#pragma comment(lib,"ws2_32.lib")//windows�µ�socket��
#else
//linuxͷ�ļ�
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
	static bool Write(const std::string& name, const std::string& body, int64_t offset = 0)//���ƫ������ҪС��4G
	{
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "wb+");
		if (fp == NULL) {
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fwrite(body.c_str(), 1, body.size(), fp);
		if (ret != body.size())
		{
			std::cerr << "���ļ�д������ʧ��\n";
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
			std::cerr << "���ļ�ʧ��\n" ;
				return false;
		}
		ofs.seekp(offset, std::ios::beg);//��дλ����ת������ļ���ʼλ�ÿ�ʼƫ�Ƶ�offsetƫ����
		ofs.write(&body[0], body.size());
		if (ofs.good() == false) {
			std::cerr << "���ļ�д������ʧ��\n";
			   ofs.close();
				return false;
		}
		ofs.close();
		return true;
	}
	*/

	//ָ�������ʾ����һ������Ͳ���
	//const & ��ʾ����һ�������Ͳ���
	//& ��ʾ����һ����������Ͳ���
	//(��������������Լ������壬���ļ��ж�ȡ������ifstream,���ļ���д��������ofstream)
	static bool Read(const std::string& name, std::string* body) {
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		std::cout << "��ȡ�ļ����ݣ�" << name << "size:" << filesize << "\n";
		FILE* fp = NULL;
		fopen_s(&fp, name.c_str(), "rb+");
		if (fp == NULL)
		{
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		int ret = fread(&(*body)[0], 1, filesize, fp);
		if (ret != filesize) {
			std::cerr << "���ļ���ȡ����ʧ��\n";
			fclose(fp);
			return false;
		}
		fclose(fp);
		return true;
#if 0
		std::ifstream ifs(name);
		if (ifs.is_open() == false)
		{
			std::cerr << "���ļ�ʧ��\n";
				return false;
		}
		int64_t filesize = boost::filesystem::file_size(name);//ͨ���ļ�����ȡ�ļ���С
		body->resize(filesize);
		std::cout << "Ҫ��ȡ���ļ���С��" << name << ":" << filesize << std::endl;
		ifs.read(&(*body)[0], filesize);
#endif
		/*
		if (ifs.good() == false)
		{
			std::cerr << "��ȡ�ļ�����ʧ��\n";
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
			std::cerr << "���ļ�ʧ��\n";
			return false;
		}
		fseek(fp, offset, SEEK_SET);
		int ret = fread(&(*body)[0], 1,len, fp);
		if (ret != len) {
			std::cerr << "���ļ���ȡ����ʧ��\n";
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
	uint32_t _ip_addr;//������IP��ַ
	uint32_t _mask_addr;//��������������
};

class AdapterUtil
{
public:
#ifdef _WIN32
	//windows�»�ȡ������Ϣʵ��
	static bool GetAllAdapter(std::vector<Adapter>* list) {
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
		//GetAdapterInfo win�»�ȡ������Ϣ�Ľӿ�
		//������Ϣ�����ж������˴���һ��ָ��

		//��ȡ������Ϣ�п��ܻ�ʧ�ܣ���Ϊ�ռ䲻�㣬
		//��˴������һ������Ͳ�������Ϊ�û���������������Ϣ�ռ�ռ�ô�С
		uint64_t all_adapter_size = sizeof(IP_ADAPTER_INFO);
		//all_adapter_size���ڻ�ȡʵ������������Ϣ��ռ�õĿռ��С
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
			if (ret == ERROR_BUFFER_OVERFLOW) {
				//��������ʾ�������ռ䲻��
				//���¸�ָ������ռ�
				delete p_adapters;
				p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
				GetAdaptersInfo(p_adapters, (PULONG)& all_adapter_size);//���»�ȡ������Ϣ
		}
			while (p_adapters) {
				Adapter adapter;
				inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String,&adapter._ip_addr);
				inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._mask_addr);
				//inet_pton(int family,char* string,void* buf)
			    //��һ���ַ������ʮ���Ƶ�IP��ַת��Ϊ�����ֽ���IP��ַ
				//family:AF_INETʹ��IPV4��ַ�ṹ
				//string:�Է������ʮ���Ƶ�IP��ַ
				//buf:һ�黺���������ڽ���ת����������ֽ���
				//adapter._ip_addr=inet_addr(p_adapters->IpAddressList.IpAddress.String);
				//adapter._mask_addr=inet_addr(p_adapters->IpAddressList.IpMask.String);
				if (adapter._ip_addr != 0) {//��Ϊ��Щ������û�����ã�����ip��ַΪ0
                    list->push_back(adapter);//��������Ϣ��ӵ�vector���ظ��û�
					std::cout << "��������:" << p_adapters->AdapterName << std::endl;
					std::cout << "����������" << p_adapters->Description << std::endl;
					std::cout << "IP��ַ��" << p_adapters->IpAddressList.IpAddress.String << std::endl;
					std::cout << "�������룺" << p_adapters->IpAddressList.IpMask.String << std::endl;
					std::cout << std::endl;
				}
				p_adapters = p_adapters->Next;
		}
			delete p_adapters;
		return true;
	}
#else
	//Linux�»�ȡ������Ϣ��ʵ��
	bool GetAllAdapter(std::vector<Adapter>* list);
#endif
};