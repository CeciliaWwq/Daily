#include<boost/filesystem.hpp>
#include"client.hpp"


void helloworld(const httplib::Request& req, httplib::Response& rsp)
{
	printf("httplib server recv a req:%s\n", req.path.c_str());
	rsp.set_content("<html><h1>HelloWorld</h><html>", "text/html");
	rsp.status = 200;
}
#if 0 
int main(int argc, char* argv[])
{
	httplib::Server srv;
	srv.Get("/", helloworld);
	srv.listen("0.0.0.0", 9000);//0.0.0.0代表本机的所有ip地址
	return 0;
}
#endif
void Scandir()
{
	//boost::filesystem::path().filename() 只获取文件名称；abc/filename.txt  ->  filename.txt
	//boost::filesystem::exists() 判断文件是否存在
	const char* ptr = "./";
	boost::filesystem::directory_iterator begin(ptr); //定义一个目录迭代器对象
	boost::filesystem::directory_iterator end;
	for (; begin != end; ++begin) {
		//begin->status()  目录中当前文件的状态信息
		//boost::filesystem::is_directory() 判断当前文件是否是一个目录
		if (boost::filesystem::is_directory(begin->status())) {
			//begin->path().string() 获取当前迭代文件的文件名
			std::cout << begin->path().string() << "是一个目录\n";
		}
		else {
			std::cout << begin->path().string() << "是一个普通文件\n";
			//begin->path().filename() 获取路文件路径名中的文件名称，而不要路径
			std::cout << "文件名：" << begin->path().filename().string() << std::endl;
		}
	}
}

#if 0
void test()
{
	Scandir();
	Sleep(1111111);
	/*
	httplib::Server srv;

	srv.Get("/", helloworld);

	srv.listen("0.0.0.0", 9000);
	*/
}
void ClientRun()
{
	Client cli;
	cli.Start();
}
#endif
void ClientRun()
{
	Sleep(1);
	Client cli;
	cli.Start();
}

int main(int argc, char* argv[])
{
	//在主线程中要运行客户端模块以及服务端模块
	//创建一个线程运行客户端模块，主线程运行服务端模块

	std::thread thr_client(ClientRun);//若客户端运行的时候服务端还没启动这是不合理的
	Server srv;
	srv.Start();
	return 0;
}