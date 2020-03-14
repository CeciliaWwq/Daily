#pragma once
#include"util.hpp"
#include<boost/filesystem.hpp>
#include<thread>
#include"httplib.h"
#define P2P_PORT 9000
#define MAX_IPBUFFER 16
#define SHARED_PATH "./Shared/"
#define DOWNLOAD_PATH "./DownLoad/"

class Host
{
public:
	uint32_t _ip_addr;//���������ip��ַ
	bool _pair_ret;//���ڴ����Խ�����ɹ�true,ʧ��false
};


class Client
{
public:
	bool Start()
	{
		//�ͻ��˳�����Ҫѭ�����У���Ϊ�����ļ�����ֻ����һ��
		//ѭ������ÿ������һ���ļ�֮�󶼻����½����������---���ǲ������
		while (1) {
			GetOnlineHost();
		}
		return true;
	}
	//������Ե��߳���ں���
	void HostPair(Host* host) {
		//1.��֯httpЭ���ʽ����������
		//2.�һ��tcp�Ŀͻ��ˣ������ݷ���
		//3.�ȴ�����˵Ļظ��������н���
		//���������ʹ�õ�������httplibʵ�֣���Ҫע�����ʵ�����̣�
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };//(255.255.255.255/0 ���ᳬ��16���ֽڣ�
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		httplib::Client cli(buf, P2P_PORT);//ʵ����httplib�ͻ��˶���
		auto rsp = cli.Get("/hostpair");//�����˷�����ԴΪ/hostpair��GET���������ӽ���ʧ��get���ؿ�
		if (rsp&&rsp->status == 200) {
			host->_pair_ret = true;     //����������Խ��
		}
		return;
	}
	   bool GetOnlineHost() {//��ȡ��������
		char ch='Y';//�Ƿ�����ƥ�䣬Ĭ���ǽ���ƥ��ģ���online������Ϊ�������û�ѡ��
			if (!_online_host.empty()) {
			std::cout << "�Ƿ����²鿴����������Y/N):";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y') {
			std::cout << "��ʼ����ƥ��...\n";
			//1.��ȡ������Ϣ���õ������������е�IP��ַ�б�
			std::vector<Adapter>list;
			AdapterUtil::GetAllAdapter(&list);
			//��ȡ��������ip��ַ����ӵ�hostlist��
			std::vector<Host>host_list;
			for (int i = 0; i < list.size(); i++)//�õ����е�����IP��ַ�б�
			{
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//���������
				uint32_t net = (ntohl(ip & mask));
				//�������������
				uint32_t max_host = (~ntohl(mask));
				//����Э�����õ��Ķ��Ǵ���ֽ��򣬵����ų��е�������С���ֽ���
				//����������Ҫ���������ֽ���ת���ɴ���ֽ��򣿣�
				//ntohs���޷��ų��������������ֽ���ת��Ϊ�����ֽ���
				//std::cout << "max_host" << (int32_t)max_host << std::endl;//**********
				if (max_host == 255)//*********
				{
					for (int j = 1; j < (int32_t)max_host; j++)
					{
						uint32_t host_ip = net + j;//���ÿ��������ip��ַ
					//ps:������Ϊ�㲻�ܷ����������������Ϊ����һ�������
						//������ȫΪ1�ĵ�ַ��һ���㲥��ַͬ��������
						//thr_list[i]=new std::thread(&Client::HostPair,this,host_ip,&ret_list[i]);
						//��forѭ���д����̣߳�ʵ��������һ���ֲ�����ѭ�������ͻᱻ�ͷ�
						//�޷���ѭ���ⲿ���еȴ��������forѭ���ⲿ����һ��
						   //vector<std::thread*>list;list[i]=new std::thread();
						//ʵ�����̶߳����ڶ������룬�����Ļ�forѭ���������򲻻ᱻ�Զ��ͷ���Ҫ�û��ֶ��ͷ�
						//���߳���ں�������һ����ĳ�Ա����ʱ��Ҫע������д��
						Host host;
						host._ip_addr = htonl(host_ip);//����������ֽ���ip��ַת��Ϊ�����ֽ���
						host._pair_ret = false;
						host_list.push_back(host);
					}
				}//************
			}
			//��host_list�е����������߳̽������
			std::vector<std::thread*> thr_list(host_list.size());
			//std::cout << "host_list.size():" << host_list.size() << std::endl;//*************
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "��������ƥ����,���Ժ�...\n" ;
			//�ȴ������߳����������ϣ��ж���Խ����������������ӵ�_online_host
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i]->join();
				if (host_list[i]._pair_ret == true)
				{
					_online_host.push_back(host_list[i]);
				}
				delete thr_list[i];
			}
		}

		//����������������ip��ӡ���������û�ѡ��
		for (int i = 0; i < _online_host.size(); i++) {
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout<<"\t" << buf<<std::endl;
		}
		//2.�����IP��ַ�б������������������
		//3.���������õ���Ӧ�����Ӧ����Ϊ��������
		//��IP��ӵ�_online_host�б���
		//4.��ӡ���������б�ʹ�û�ѡ��
		std::cout << "��ѡ�������������ȡ�����ļ��б�";
			fflush(stdout);
			std::string select_ip;
			std::cin >> select_ip;
			GetShareList(select_ip);
				//�û�ѡ������֮�󣬵��û�ȡ�ļ��б�ӿ�
			return true;
	}
	bool GetShareList(const std::string& host_ip)//��ȡ�ļ��б�
	{
		//�����˷���һ���ļ��б��ȡ����
		//1.�ȷ�������
		//2.�õ���Ӧ֮�󣬽������ģ��ļ����ƣ�
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200) {
			std::cerr << "��ȡ�ļ��б���Ӧ����\n";
			return false;
		}
		//��ӡ����--��ӡ��������Ӧ���ļ������б��û�ѡ��
		//body:filename1\r\nfilename2\r\n
		std::cout << rsp->body << std::endl;
		std::cout << "\n��ѡ��Ҫ���ص��ļ���";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		DownloadFile(host_ip, filename);
			return true;
	}
	bool DownloadFile(const std::string& host_ip, const std::string& filename)//�����ļ�
	{
		//1.������������ļ���������
		//2.�õ���Ӧ�������Ӧ����е�body���ľ����ļ�����
		//3.�����ļ������ļ�д���ļ��У��ر��ļ�
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip, P2P_PORT);
		std::cout << "�����˷����ļ���������" << host_ip<<":"<<req_path << std::endl;
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "�����ļ�����ȡ�ļ���Ϣʧ��\n"<<std::endl;
			if (rsp->status != NULL)
			{
				std::cout << rsp->status << std::endl;
					
			}
				return false;
		}
		std::cout << "��ȡ�ļ�������Ӧ�ɹ�\n";
		if (!boost::filesystem::exists(DOWNLOAD_PATH)) {
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH + filename;
		if (FileUtil::Write(filename, rsp->body,0)== false) {
			std::cerr << "�ļ�����ʧ��\n";
				return false;
		}
		return true;
	}

private:
	std::vector<Host> _online_host;
};
class Server
{
public:
	bool Start()
	{
		//�����Կͻ�����Ĵ���ʽ��Ӧ��ϵ
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		_srv.Get("/download/.*", Download);//������ʽ���������ַ���ָ���ĸ�ʽ����ʾ���йؼ�����������;
		//'.'ƥ�������\n��\r֮��������ַ���'*'��ʾƥ��ǰ����ַ������
		//��download�����壺��ֹ���Ϸ���ָ���ͻ
		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
	}
private:
	static void HostPair(const httplib::Request& req, httplib::Response& rsp) {
		rsp.status = 200;
		return;
	}
	//��ȡ�����ļ��б�--������������һ������Ŀ¼,��������ļ��ϵĶ���Ҫ��������˵�
	static void ShareList(const httplib::Request& req, httplib::Response& rsp) {
		//1.�鿴Ŀ¼�Ƿ���ڣ���Ŀ¼�����ڣ��򴴽����Ŀ¼
		if (!boost::filesystem::exists(SHARED_PATH)) {
			boost::filesystem::create_directory(SHARED_PATH);
		}
		boost::filesystem::directory_iterator begin(SHARED_PATH);//ʵ����Ŀ¼������
		boost::filesystem::directory_iterator end;//ʵ����Ŀ¼��������ĩβ
		//��ʼ����Ŀ¼
		for (; begin != end; ++begin)
		{
			if (boost::filesystem::is_directory(begin->status())) {
				//��ǰ�汾����ֻ��ȡ��ͨ�ļ����ƣ�������㼶Ŀ¼�Ĳ���
				continue;
			}
			std::string name = begin->path().filename().string();//ֻҪ�ļ�����Ҫ·��
			rsp.body += name + "\r\n";  //filename1\r\n filename2\r\n...
		}
		rsp.status = 200;
		return;
	}
	static void Download(const httplib::Request& req, httplib::Response& rsp) {
		std::cout << "������յ��ļ���������" << req.path << std::endl;
		//req.path-�ͻ����������Դ·�� /download/filename
		boost::filesystem::path req_path(req.path);
		std::string name = req_path.filename().string();//ֻ��ȡ�ļ����ƣ�
		std::cout << "������յ��ļ���������:" << name << "·��:" << SHARED_PATH<<std::endl;
		std::string realpath = SHARED_PATH + name; //ʵ���ļ���·��Ӧ�����ڹ����Ŀ¼��
		//boost::filesystem::exists()�ж�Ϊ�ļ��Ƿ����
		std::cout << "������յ���ʵ������·����" << realpath;
		if (boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath)) {
			rsp.status = 404;
			return;
		};
	if (FileUtil::Read(realpath, &rsp.body) == false) {
		rsp.status = 500;
		return;

	}
	rsp.status = 200;
	return;
};
private:
	httplib::Server _srv;
};