/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////
// Socks5 ����ͷ�ļ�������Э��������ݰ��ṹ
// �汾 0.1������ ����
// 2007 �� 1 �� 9 ���賿 1 �� 15 �֣�GF �ؼ��Ѿ� 11 ���ˡ�
// 2008 �� 1 �� 25 ���޸ģ����� GF һֱ������ߣ�����
//
// �ο���
// http://www.rfc-editor.org/rfc/rfc1928.txt
// http://www.rfc-editor.org/rfc/rfc1929.txt
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////
#ifndef SOCKS5_H
#define SOCKS5_H
#define VERSION 0x05
#define CONNECT 0x01
#define IPV4 0x01
#define DOMAIN 0x03
#define IPV6 0x04
typedef struct _method_select_response // Э�̷�����������Ӧ
{
	char version; // ������֧�ֵ� Socks �汾��0x04 ���� 0x05
	char select_method;// ������ѡ��ķ�����0x00 Ϊ������0x02 Ϊ������֤
} METHOD_SELECT_RESPONSE;
typedef struct _method_select_request // Э�̷������������
{
	char version; // �ͻ���֧�ֵİ汾��0x04 ���� 0x05
	char number_methods; // �ͻ���֧�ֵķ���������
	char methods[255]; // �ͻ���֧�ֵķ������ͣ���� 255 ����0x00 Ϊ������0x02 Ϊ������֤
} METHOD_SELECT_REQUEST;
typedef struct _AUTH_RESPONSE // �û�������֤�������Ӧ
{
	char version;// �汾���˴��㶨Ϊ 0x01
	char result;// �������֤�����0x00 Ϊ�ɹ���������Ϊʧ��
} AUTH_RESPONSE;
typedef struct _AUTH_REQUEST //�û�������֤�ͻ�������
{
	char version; // �汾���˴��㶨Ϊ 0x01
	char name_len; // �������ֶ��û����ĳ��ȣ�һ���ֽڣ��Ϊ 0xff
	char name[255]; // �û���
	char pwd_len;// ���ĸ��ֶ�����ĳ��ȣ�һ���ֽڣ��Ϊ 0xff
	char pwd[255]; // ����
} AUTH_REQUEST;
typedef struct _SOCKS5_RESPONSE // ������ʵ������Socks �����������Ӧ
{
	char version; // ������֧�ֵ� Socks �汾��0x04 ���� 0x05
	char reply; // ���������������ʵ�����Ľ����0x00 �ɹ�
	char reserved; // ����λ���㶨λ 0x00
	char address_type; // Socks ����������󶨵ĵ�ַ���ͣ�IP V4 Ϊ 0x01,IPV6 Ϊ 0x04������Ϊ 0x03
	char address_port[1]; // ��� address_type Ϊ�������˴���һ�ֽ�Ϊ�������ȣ����Ϊ���������� 0 �ַ���β,������Ϊ Socks ����������󶨶˿�
}SOCKS5_RESPONSE;
typedef struct _SOCKS5_REQUEST // �ͻ�������������ʵ����
{
	char version; // �ͻ���֧�ֵ� Socks �汾��0x04 ���� 0x05
	char cmd; // �ͻ������CONNECT Ϊ 0x01 �� BIND Ϊ 0x02 �� UDP Ϊ 0x03��һ��Ϊ 0x01
	char reserved; // ����λ���㶨λ 0x00
	char address_type; 
}SOCKS5_REQUEST;
#endif