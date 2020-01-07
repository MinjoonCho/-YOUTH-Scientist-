#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h> 

//기본적인 변수 
char tmp_send[1000];	//임시작으로 데이터 받는 곳 
char tmp_recv[1000];	//입시적으로 줄 데이터 넣는 곳 
int strLen = 0;	//시스템변수(받은 리스트 길이) 
short tmp1, tmp2, tmp3 = 0;	//프로그램에서 임시적으로 저장하는 숫자값 
char tmp4;
char str_tmp1[100];


//logIN, logOUT
char username [50][100];	//학생 이름 답는 리스트 
char pw [50][100];	//학생 PW 담는 리스트 

//출석체크 
char chul [2][100];

//질문 
char question[1000][500];	//질문들 
char answer[1000][500];		//답들(해당하는 리스트 번호에) 

//링크 자료 
char link[1000][500];	//링크 저장 

//개인 채팅 
char chat [500][503];

//팀 채팅 
char team_chat[500][503];

void ErrorHandling(char* message);
int main(int argc, char* argv[])
{
	//connection build
	WSADATA wsaData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAddr, clntAddr;

	int szClntAddr;
	if(argc!=2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	if(WSAStartup(MAKEWORD(2, 2), &wsaData)!=0)
		ErrorHandling("WSAStartup() error!");

	hServSock=socket(PF_INET, SOCK_STREAM, 0);
	if(hServSock==INVALID_SOCKET)
		ErrorHandling("socket() error");

		memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddr.sin_port=htons(atoi(argv[1]));

	if(bind(hServSock, (SOCKADDR*) &servAddr, sizeof(servAddr))==SOCKET_ERROR)
		ErrorHandling("bind() error");

	if(listen(hServSock, 5)==SOCKET_ERROR)
		ErrorHandling("listen() error");

	szClntAddr=sizeof(clntAddr);
	hClntSock=accept(hServSock, (SOCKADDR*)&clntAddr, &szClntAddr);
	if(hClntSock==INVALID_SOCKET)
		ErrorHandling("accept() error");

/*여가부터 코드 작성*/ 
	// connection build finish. Let's send own message
	
	while(1){	//계속 돌아가는 루프 
		printf("선생님, 환영합니다.");
		Sleep(1000);
		print("\n\n\n\n\n");
		printf("┌──────────────────────────────────────────────────────────────────────────────┐\n");
		printf("│          카이스트 YOUTH Scientist Camp 학습 보조 프로그램                    │\n");
		printf("│         1.출석 확인                        5.개별 메시지                     │\n");
		printf("│         2.질문 받기                        6.팀 채팅                         │\n");
		printf("│         3.링크 리스트                      7.각 학생들 로그인,아웃           │\n");
		printf("│         4.선생님 전달 사항                 8.프로그램 종료                   │\n");
		printf("└──────────────────────────────────────────────────────────────────────────────┘\n");
		printf(":");
		scanf("%s", &tmp4);
		switch (tmp4) {
			case('1'): 
				
				break;
			case('2'):
				 
				break;
			case('3'):
				 
				break;
			case('4'): 
				
				break;
			case('5'): 
				
				break;
			case('6'): 
				
				break;
			case('7'): 
				
				break;
			case('8'): 
				
				break;
		}
	}
	
/*쑬 수 있는 함수들 */
//	메모리 초기화 
//	memset(send_msg,'\0', sizeof(send_msg));
//	memset(rcv_msg, '\0', sizeof(rcv_msg));
//메세지 센드 
//	send(hClntSock, send_msg, sizeof(send_msg),0);
//메세지 리시브 
//	strLen=recv(hClntSock, 내가 넣을 메세지, sizeof(내가 넣을 메세지)-1, 0);
//	if(strLen==-1)
//		ErrorHandling("read() error!"); 

/*	전체종료*/ 
	closesocket(hClntSock);
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
