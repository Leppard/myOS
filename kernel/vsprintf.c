
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              vsprintf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "string.h"

/*
 *  Ϊ���õ����˺�����ԭ���ɲο� printf ��ע�Ͳ��֡�
 */

/*======================================================================*
                                vsprintf
 *======================================================================*/
int vsprintf(char *buf, const char *fmt, va_list args)
{
	char*	p;
	char	tmp[256];
	va_list	p_next_arg = args;

	for (p=buf;*fmt;fmt++) {
		if (*fmt != '%') {
			*p++ = *fmt;
			continue;
		}

		fmt++;

		switch (*fmt) {
		case 'X':
		case 'x':
			itoa(tmp, *((int*)p_next_arg));
			strcpy(p, tmp);
			p_next_arg += 4;
			p += strlen(tmp);
			break;
		case 'D':
		case 'd':
		{		
			itoa_dec(tmp, *((int*)p_next_arg));//��һ����ת��Ϊ�ַ���
			strcpy(p, tmp);
			p_next_arg += 4;
			p += strlen(tmp);
			break;
		}
		case 'c'://���һ���ַ�
		{
			*p++=*p_next_arg;
			p_next_arg+=4;
			break;
		}
		case 's':
			break;
		default:
			break;
		}
	}

	return (p - buf);
}

