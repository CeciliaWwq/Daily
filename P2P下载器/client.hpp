#pragma once
#include"util.hpp"
#include<boost/filesystem.hpp>
#include<thread>
#include"httplib.h"
#define P2P_PORT 9000
#define MAX_IPBUFFER 16
//1左移10位 1k  左移20位 1M
#define MAX_RANGE (100*1024*1024)//100M
#define SHARED_PATH "./Shared/"
#define DOWNLOAD_PATH "./DownLoad/"

class Host
{
public:
	uint32_t _ip_addr;//配对主机的ip地址
	bool _pair_ret;//用于存放配对结果，成功true,失败false
};


class Client
{
public:
	bool Start()
	{
		//客户端程序需要循环运行，因为下载文件不是只下载一次
		//循环运行每次下载一个文件之后都会重新进行主机配对---这是不合理的
		while (1) {
			GetOnlineHost();
		}
		return true;
	}
	//主机配对的线程入口函数
	void HostPair(Host* host) {
		//1.组织http协议格式的请求数据
		//2.搭建一个tcp的客户端，将数据发送
		//3.等待服务端的回复，并进行解析
		//这个过程是使用第三方库httplib实现（但要注意具体实现流程）
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };//(255.255.255.255/0 不会超过16个字节）
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);
		httplib::Client cli(buf, P2P_PORT);//实例化httplib客户端对象
		auto rsp = cli.Get("/hostpair");//向服务端发送资源为/hostpair的GET请求，若连接建立失败get返回空
		if (rsp&&rsp->status == 200) {
			host->_pair_ret = true;     //重置主机配对结果
		}
		return;
	}
	   bool GetOnlineHost() {//获取在线主机
		char ch='Y';//是否重新匹配，默认是进行匹配的，若online主机不为空则让用户选择
			if (!_online_host.empty()) {
			std::cout << "是否重新查看在线主机（Y/N):";
			fflush(stdout);
			std::cin >> ch;
		}
		if (ch == 'Y') {
			std::cout << "开始主机匹配...\n";
			//1.获取网卡信息，得到局域网中所有的IP地址列表
			std::vector<Adapter>list;
			AdapterUtil::GetAllAdapter(&list);
			//获取所有主机ip地址，添加到hostlist中
			std::vector<Host>host_list;
			for (int i = 0; i < list.size(); i++)//得到所有的主机IP地址列表
			{
				uint32_t ip = list[i]._ip_addr;
				uint32_t mask = list[i]._mask_addr;
				//计算网络号
				uint32_t net = (ntohl(ip & mask));
				//计算最大主机号
				uint32_t max_host = (~ntohl(mask));
				//网络协议所用到的都是大端字节序，但不排除有的主机是小端字节序
				//所以这里需要把主机的字节序都转化成大端字节序？？
				//ntohs把无符号长整形数从网络字节序转化为主机字节序
				//std::cout << "max_host" << (int32_t)max_host << std::endl;//**********
				if (max_host == 255)//*********
				{
					for (int j = 1; j < (int32_t)max_host; j++)
					{
						uint32_t host_ip = net + j;//获得每个主机的ip地址
					//ps:主机号为零不能分配给主机，主机号为零是一个网络号
						//主机号全为1的地址是一个广播地址同样不能用
						//thr_list[i]=new std::thread(&Client::HostPair,this,host_ip,&ret_list[i]);
						//在for循环中创建线程，实例化的是一个局部对象，循环起来就会被释放
						//无法在循环外部集中等待，因此在for循环外部创建一个
						   //vector<std::thread*>list;list[i]=new std::thread();
						//实例化线程对象在堆上申请，这样的话for循环运行完则不会被自动释放需要用户手动释放
						//当线程入口函数，是一个类的成员函数时需要注意以上写法
						Host host;
						host._ip_addr = htonl(host_ip);//将这个主机字节序ip地址转化为网络字节序
						host._pair_ret = false;
						host_list.push_back(host);
					}
				}//************
			}
			//对host_list中的主机创建线程进行配对
			std::vector<std::thread*> thr_list(host_list.size());
			//std::cout << "host_list.size():" << host_list.size() << std::endl;//*************
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
			}
			std::cout << "正在主机匹配中,请稍后...\n" ;
			//等待所有线程主机配对完毕，判断配对结果，将在线主机添加到_online_host
			for (int i = 0; i < host_list.size(); i++) {
				thr_list[i]->join();
				if (host_list[i]._pair_ret == true)
				{
					_online_host.push_back(host_list[i]);
				}
				delete thr_list[i];
			}
		}

		//将所有在线主机的ip打印出来，供用户选择
		for (int i = 0; i < _online_host.size(); i++) {
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout<<"\t" << buf<<std::endl;
		}
		//2.逐个对IP地址列表中主机发送配对请求
		//3.若配对请求得到相应，则对应主机为在线主机
		//则将IP添加到_online_host列表中
		//4.打印在线主机列表，使用户选择
		std::cout << "请选择配对主机，获取共享文件列表：";
			fflush(stdout);
			std::string select_ip;
			std::cin >> select_ip;
			GetShareList(select_ip);
				//用户选择主机之后，调用获取文件列表接口
			return true;
	}
	bool GetShareList(const std::string& host_ip)//获取文件列表
	{
		//向服务端发送一个文件列表获取请求
		//1.先发送请求
		//2.得到响应之后，解析正文（文件名称）
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Get("/list");
		if (rsp == NULL || rsp->status != 200) {
			std::cerr << "获取文件列表相应错误\n";
			return false;
		}
		//打印正文--打印服务器相应的文件名称列表供用户选择
		//body:filename1\r\nfilename2\r\n
		std::cout << rsp->body << std::endl;
		std::cout << "\n请选择要下载的文件：";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		RangeDownload(host_ip, filename);
			return true;
	}
	bool DownloadFile(const std::string& host_ip, const std::string& filename)//下载文件
	{
		//1.向服务器发送文件下载请求
		//2.得到相应结果，响应结果中的body正文就是文件数据
		//3.创建文件，将文件写入文件中，关闭文件
		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip, P2P_PORT);
		std::cout << "向服务端发送文件下载请求：" << host_ip<<":"<<req_path << std::endl;
		auto rsp = cli.Get(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "下载文件，获取文件信息失败\n"<<std::endl;
			if (rsp->status != NULL)
			{
				std::cout << rsp->status << std::endl;
					
			}
				return false;
		}
		std::cout << "获取文件下载响应成功\n";
		if (!boost::filesystem::exists(DOWNLOAD_PATH)) {
			boost::filesystem::create_directory(DOWNLOAD_PATH);
		}
		std::string realpath = DOWNLOAD_PATH + filename;
		if (FileUtil::Write(filename, rsp->body,0)== false) {
			std::cerr << "文件下载失败\n";
				return false;
		}
		std::cout << "文件下载成功!" << std::endl;
		return true;
	}
	bool RangeDownload(const std::string& host_ip, const std::string& name)
	{
		//若文件一次性下载，遇到大文件比较危险，所以采用分块下载
		//1.发送Head请求，通过响应中的Content-Length获取文件大小
		std::string req_path = "/download/" + name;
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Head(req_path.c_str());
		if (rsp == NULL || rsp->status != 200)
		{
			std::cout << "获取文件大小信息失败\n";
			return false;
		}
		std::string clen = rsp->get_header_value("Content-Length");
		int64_t filesize = StringUtil::Str2Dig(clen);
		
		//2.根据文件大小进行分块
		//int range_count = filesize / MAX_RANGE;
			//a.若文件大小小于块大小直接下载文件
			if (filesize < MAX_RANGE)
			{
				std::cout << "文件较小直接下载文件\n";
				return DownloadFile(host_ip, name);
			}
			//计算分块个数
			//b.若文件大小不能整除块大小，则分块个数为文件大小除以分块大小然后+1
			//c.若文件大小刚好整除分块大小，则分块个数就是文件大小除以分块大小
			std::cout << "文件过大，分块进行下载\n";
			int range_count = 0;
			if (filesize % MAX_RANGE == 0)
			{
				range_count = filesize / MAX_RANGE;
			}
			else {
				range_count = (filesize / MAX_RANGE) + 1;
			}
			//计算分块大小
			int64_t range_start = 0,range_end=0;
			for (int i = 0; i < range_count; i++)
			{
				range_start = i * MAX_RANGE;
				if (i == (range_count)-1)
				{
					range_end = filesize - 1;
				}
				else range_end = ((i + 1) * MAX_RANGE)-1;
				std::cout << "客户端请求分块：" << range_start << "-" << range_end<<std::endl;
				//3.逐一请求分块数据，得到响应之后写入文件指定位置

				httplib::Headers header;
				std::stringstream tmp;
				tmp << "bytes=" << range_start << "-" << range_end;
				header.insert(std::make_pair("Range",tmp.str()));
				//header.insert(httplib::make_range_header({ {range_start,range_end} }));//设置一个range区间
				httplib::Client cli(host_ip.c_str(), P2P_PORT);
				auto rsp=cli.Get(req_path.c_str(), header);
				if (rsp == NULL || rsp->status != 206) {
					std::cout << "区间下载文件失败\n";
					return false;
				}
				std::cout << "客户端分块写入文件[" << rsp->body << "]\n";
				FileUtil::Write(name, rsp->body, range_start);
				std::cout << "客户端分块写入文件成功\n" << std::endl;
			}
			std::cout << "文件下载成功\n";
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
		//添加针对客户请求的处理方式对应关系
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		_srv.Get("/download/.*", Download);//正则表达式：将特殊字符以指定的格式，表示具有关键特征的数据;
		//'.'匹配任意除\n或\r之外的任意字符，'*'表示匹配前面的字符任意次
		//加download的意义：防止与上方的指令冲突
		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
	}
private:
	static void HostPair(const httplib::Request& req, httplib::Response& rsp) {
		rsp.status = 200;
		return;
	}
	//获取共享文件列表--在主机上设置一个共享目录,凡是这个文件上的都是要分享给别人的
	static void ShareList(const httplib::Request& req, httplib::Response& rsp) {
		//1.查看目录是否存在，若目录不存在，则创建这个目录
		if (!boost::filesystem::exists(SHARED_PATH)) {
			boost::filesystem::create_directory(SHARED_PATH);
		}
		boost::filesystem::directory_iterator begin(SHARED_PATH);//实例化目录迭代器
		boost::filesystem::directory_iterator end;//实例化目录迭代器的末尾
		//开始迭代目录
		for (; begin != end; ++begin)
		{
			if (boost::filesystem::is_directory(begin->status())) {
				//当前版本我们只获取普通文件名称，不做多层级目录的操作
				continue;
			}
			std::string name = begin->path().filename().string();//只要文件名不要路径
			rsp.body += name + "\r\n";  //filename1\r\n filename2\r\n...
		}
		rsp.status = 200;
		return;
	}
	static void Download(const httplib::Request& req, httplib::Response& rsp) {
		std::cout << "服务端收到文件下载请求：" << req.path << std::endl;
		//req.path-客户端请求的资源路径 /download/filename
		boost::filesystem::path req_path(req.path);
		std::string name = req_path.filename().string();//只获取文件名称；
		std::cout << "服务端收到文件下载名称:" << name << "路径:" << SHARED_PATH << std::endl;
		std::string realpath = SHARED_PATH + name; //实际文件的路径应该是在共享的目录下
		//boost::filesystem::exists()判断为文件是否存在
		std::cout << "服务端收到的实际下载路径：" << realpath << std::endl;
		//判断文件是否存在 或者 这个文件是‘目录’---404
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath)) {
			std::cout << "realpath" << realpath << std::endl;
			rsp.status = 404;
			return;
		}
		if (req.method == "GET") {
			//以前Get就是直接下载一整个文件，但是现在不一样了有了分块传输这个功能
			//判断是否是分块传输的依据，就是这次请求中是否有Range头部字段
			if (req.has_header("Range")) {//判断请求头中是否包含Range字段
				//如果包含这就是一个分块传输
				//需要知道分块区间是多少
				std::string range_str = req.get_header_value("Range");//byte=start-end
				httplib::Ranges ranges;//vector<Range> Range-std::pair<start,end>
				httplib::detail::parse_range_header(range_str, ranges);//解析客户端的range数据
				int64_t range_start=ranges[0].first;//pair中second就是range的end位置
				int64_t range_end = ranges[0].second;
				int64_t range_len = range_end - range_start+1;
				std::cout <<realpath<< ":range:" << range_start << "-" << range_end << std::endl;
				FileUtil::ReadRange(realpath, &rsp.body, range_len, range_start);
				rsp.status = 206;
				std::cout << "服务端响应区间数据完毕\n["<<rsp.body<<"]\n";
			}else {
				//没有range头部，则是一个完整的文件下载
				if (FileUtil::Read(realpath, &rsp.body) == false) {
					rsp.status = 500;
					return;
				}
				rsp.status = 200;
			}
			
		}
		else {
			//这是针对head请求的--客户端只要头部不要正文
			int64_t filesize = FileUtil::GetFileSize(realpath);
			rsp.set_header("Content-Length", std::to_string(filesize));//设置响应头部信息接口
			rsp.status = 200;
		}
		std::cout << "服务端文件下载完毕"<<std::endl;
	return;
};
private:
	httplib::Server _srv;
};