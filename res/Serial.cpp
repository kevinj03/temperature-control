#include "stdafx.h"
#include <conio.h>
#define WM_COMM WM_USER+100;
class CCOM
{
public:
	char readbyte();
	void sendbyte(unsigned char sdata);
	void sendstrn(CString mess);
	void initcom(int PORT=0x2f8);//串口初始化子程序
	int port;
};
char CCOM::readbyte()//接收字符子程序
{
int time_limit=50000;
char sta;
while ((sta=inp(port+5) & 0x01) !=1)
{ time_limit--;
if (time_limit==0)
return 0;
}
//AfxGetMainWnd()->SendMessage(WM_COMM);
return inp(port);
}
void CCOM::sendbyte(unsigned char sdata)//发送字符子程序
{
int time_limit=50000;
while ((inp(port+5) & 0xf0) != 0x60)
	{ time_limit--;
	if (time_limit==0) break;
	}
outp(port,sdata);
}
void CCOM::sendstrn(CString mess)
{
int i,j=mess.GetLength();
for (i=0;i<j; i++)
sendbyte(mess[i]);
/*sendbyte(0X0A); */
}
void CCOM::initcom(int PORT)//串口初始化子程序
{
char i;
outp(PORT+3,0x80);
outp(PORT,0x0C); /* baud rate 9600 */
outp(PORT+1,0);
/*8bit 1stop no even */
outp(PORT+3 ,0x3a);
outp(PORT+3 ,0x03); 
i=inp(PORT+5) & 0xfe; 
outp(PORT+5,i);
}


