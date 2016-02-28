/**
******************************************************************************
* @file    mico_wlan.h 
* @author  
* @version V1.0.0
* @date    
* @brief   
******************************************************************************
*
*  The MIT License
*  Copyright (c) 2014 MXCHIP Inc.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy 
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights 
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is furnished
*  to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
*  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************
*/ 
#include "MQTTPacket.h"
#include "MICO.h"
#include "SocketUtils.h"

#define tcp_client_log(M, ...) custom_log("TCP", M, ##__VA_ARGS__)

int tcp_fd = -1;
fd_set readfds;
/**
  * @brief  通过TCP方式发送数据到TCP服务器
  * @param  buf 数据首地址
  * @param  buflen 数据长度
  * @retval 小于0表示发送失败
  */
int transport_sendPacketBuffer(unsigned char* buf, int buflen)
{
   int len;
  
    len = send( tcp_fd, buf, buflen, 0 );
    tcp_client_log("Client fd: %d, send data %d", tcp_fd, len);
  return len;
}
/**
  * @brief  阻塞方式接收TCP服务器发送的数据
  * @param  buf 数据存储首地址
  * @param  count 数据缓冲区长度
  * @retval 小于0表示接收数据失败
  */
int transport_getdata(unsigned char* buf, int count)
{
  //return recv(SOCK_TCPS,buf,count);
  int len;
  
    FD_ZERO( &readfds );
    FD_SET( tcp_fd, &readfds );
     /* recv wlan data, and send back */
    if( FD_ISSET( tcp_fd, &readfds ) )
    {
      len = recv( tcp_fd, buf, count, 0);
    
      
      if( len == 0){
        tcp_client_log( "TCP Client is disconnected, fd: %d", tcp_fd );
      }  
    }
  return len;
}


/**
  * @brief  打开一个socket并连接到服务器
  * @param  无
  * @retval 小于0表示打开失败
  */


int transport_open()
{

  OSStatus err;
  struct sockaddr_t addr;

  
 static char tcp_remote_ip[16] = "112.74.133.7"; /*remote ip address*/
static int tcp_remote_port = 1883;               /*remote port*/
  
  
  tcp_fd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
  
  addr.s_ip = inet_addr( tcp_remote_ip );
  addr.s_port = tcp_remote_port;
  
  tcp_client_log( "Connecting to server: ip=%s  port=%d!", tcp_remote_ip,tcp_remote_port );
  err = connect( tcp_fd, &addr, sizeof( addr ) );
  tcp_client_log( "Connect success!" );
;
  
  return 1;
}

int transport_close()
{
   SocketClose(&tcp_fd) ;
    return 1;
}
