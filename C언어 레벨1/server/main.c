#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h> 

//�⺻���� ���� 
char tmp_send[1000];	//�ӽ������� ������ �޴� �� 
char tmp_recv[1000];	//�Խ������� �� ������ �ִ� �� 
int strLen = 0;	//�ý��ۺ���(���� ����Ʈ ����) 
short tmp1, tmp2, tmp3 = 0;	//���α׷����� �ӽ������� �����ϴ� ���ڰ� 
char tmp4;
char str_tmp1[100];


//logIN, logOUT
char username [50][100];	//�л� �̸� ��� ����Ʈ 
char pw [50][100];	//�л� PW ��� ����Ʈ 

//�⼮üũ 
char chul [2][100];

//���� 
char question[1000][500];	//������ 
char answer[1000][500];		//���(�ش��ϴ� ����Ʈ ��ȣ��) 

//��ũ �ڷ� 
char link[1000][500];	//��ũ ���� 

//���� ä�� 
char chat [500][503];

//�� ä�� 
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

/*�������� �ڵ� �ۼ�*/ 
	// connection build finish. Let's send own message
	
	while(1){	//��� ���ư��� ���� 
		printf("������, ȯ���մϴ�.");
		Sleep(1000);
		print("\n\n\n\n\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��          ī�̽�Ʈ YOUTH Scientist Camp �н� ���� ���α׷�                    ��\n");
		printf("��         1.�⼮ Ȯ��                        5.���� �޽���                     ��\n");
		printf("��         2.���� �ޱ�                        6.�� ä��                         ��\n");
		printf("��         3.��ũ ����Ʈ                      7.�� �л��� �α���,�ƿ�           ��\n");
		printf("��         4.������ ���� ����                 8.���α׷� ����                   ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
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
	
/*�� �� �ִ� �Լ��� */
//	�޸� �ʱ�ȭ 
//	memset(send_msg,'\0', sizeof(send_msg));
//	memset(rcv_msg, '\0', sizeof(rcv_msg));
//�޼��� ���� 
//	send(hClntSock, send_msg, sizeof(send_msg),0);
//�޼��� ���ú� 
//	strLen=recv(hClntSock, ���� ���� �޼���, sizeof(���� ���� �޼���)-1, 0);
//	if(strLen==-1)
//		ErrorHandling("read() error!"); 

/*	��ü����*/ 
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
