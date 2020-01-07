/*parameter.h
이 헤더파일은 프로그램에 필요한 모든변수를 축하는 헤더이다.
*/ 

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
