#include"clsscr.h"
/*这是一个确定cpu coretemp目录的程序。将确定的目录名写入/tmp/sysini_ASDFsi12FBCJK9_uiGYM.iin文件。
 同时该程序加入到systemd中保证开机自动获取，留待conky中的cpu温度获取程序使用
 	tybitsfox		2022-4-26
 */
#define	SFILE	"/tmp/sysini_ArsS0DFsi12FBCJK9_uiGYM.iin"
#define Ddir	"/sys/class/hwmon/hwmon"
#define zero(A)	memset(A,0,sizeof(A))
//office lenovo pad:gup amd,os:ubuntu20.04,hwmon_name:amdgpu
int main(int argc,char **argv);









