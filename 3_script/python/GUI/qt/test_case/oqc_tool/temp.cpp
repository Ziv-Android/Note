int ChangeDeviceNetwork(unsigned long dsn_height,
  unsigned long dsn_low,
  const char* multicast_addr,
  unsigned short multicast_port,
  unsigned long new_ipaddr,
  unsigned long new_gateway,
  unsigned long new_ipmask){

  struct sockaddr_in peeraddr, myaddr;
  int sockfd;
  char send_buffer[MAX_PACKET_SIZE];
  unsigned int socklen;
  int res = -1;

  vector<string> vecIP;
  getIP( vecIP );

  int nSize = vecIP.size( );
  for( int i = 0; i < nSize; i++ )
  {
   memset(send_buffer, 0, MAX_PACKET_SIZE);

   // Create Socket
   sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

   if (sockfd == -1) {
    printf("socket creating error\n");
    return CHANGE_FAILURE;
   }
   socklen = sizeof(struct sockaddr_in);

   int ttl = 255;
   res = setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL,
    (const char *)&ttl, sizeof(ttl));
   if (res == -1){
    printf("setsockopt IP_MULTICAST_LOOP fall\n");
#if WIN32
    closesocket(sockfd);
#endif
#ifdef LINUX
    close(sockfd);
#endif
    return 1;
   }

   u_char loop = 0;
   res = setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_LOOP,
    (const char *)&loop, sizeof(loop));
   if (res == -1){
    printf("setsockopt IP_MULTICAST_LOOP fall\n");
#if WIN32
    closesocket(sockfd);
#endif
#ifdef LINUX
    close(sockfd);
#endif
    return CHANGE_FAILURE;
   }


   // Setting multicast addr and port
   memset(&peeraddr, 0, socklen);
   peeraddr.sin_family = AF_INET;
   peeraddr.sin_port = htons(multicast_port);
   peeraddr.sin_addr.s_addr = inet_addr(multicast_addr);

// #ifdef WIN32
   // Setting local bind addr and port
   memset(&myaddr, 0, socklen);
   myaddr.sin_family = AF_INET;
   myaddr.sin_port = htons(23456);

   myaddr.sin_addr.s_addr = inet_addr(vecIP[i].c_str());

   printf("sin_addr s_addr: %s.\n", vecIP[i].c_str());

   // Bind at local interface
   if (bind(sockfd, (struct sockaddr *) &myaddr, sizeof(struct sockaddr_in)) == -1) {
    printf("Bind error\n");
#if WIN32
    closesocket(sockfd);
#endif
#ifdef LINUX
    close(sockfd);
#endif
    return CHANGE_FAILURE;
   }
// #endif

#ifdef _DEBUG
   socklen_t len = 0;
   len = sizeof(struct sockaddr_in);
   getsockname(sockfd, (struct sockaddr *)&myaddr, &len);

   //printf("addr:%s\n", inet_ntoa(myaddr.sin_addr));
   //printf("port:%d\n", myaddr.sin_port);
#endif
   unsigned long dsn_height_2 = htonl(dsn_height);
   unsigned long dsn_low_2 = htonl(dsn_low);
   unsigned long new_ipaddr_2 = htonl(new_ipaddr);
   unsigned long new_gateway_2 = htonl(new_gateway);
   unsigned long new_ipmask_2 = htonl(new_ipmask);
   memcpy(send_buffer, (const void *)(&dsn_height_2), 4);
   memcpy(send_buffer + 4, (const void *)(&dsn_low_2), 4);
   memcpy(send_buffer + 8, (const void *)(&new_ipaddr_2), 4);
   memcpy(send_buffer + 12, (const void *)(&new_gateway_2), 4);
   memcpy(send_buffer + 16, (const void *)(&new_ipmask_2), 4);

   /* 发送小端消息 */
   if (sendto(sockfd, send_buffer, MAX_PACKET_SIZE, 0,
    (struct sockaddr *) &peeraddr, sizeof(struct sockaddr_in)) < 0){
     printf("sendto error!\n");
#if WIN32
     closesocket(sockfd);
#endif
#ifdef LINUX
     close(sockfd);
#endif
     return CHANGE_FAILURE;
   }

#ifdef WIN32
   Sleep(20);
#endif

   memcpy(send_buffer, (const void *)(&dsn_height), 4);
   memcpy(send_buffer + 4, (const void *)(&dsn_low), 4);
   memcpy(send_buffer + 8, (const void *)(&new_ipaddr), 4);
   memcpy(send_buffer + 12, (const void *)(&new_gateway), 4);
   memcpy(send_buffer + 16, (const void *)(&new_ipmask), 4);

   /* 发送大端消息 */
   if (sendto(sockfd, send_buffer, MAX_PACKET_SIZE, 0,
    (struct sockaddr *) &peeraddr, sizeof(struct sockaddr_in)) < 0){
     printf("sendto error!\n");
#if WIN32
              closesocket(sockfd);
#endif
#ifdef LINUX
     close(sockfd);
#endif
     return CHANGE_FAILURE;
   }

   printf("send ok\n");

#ifdef _DEBUG
   //printf("send ok\n");
#endif

#if WIN32
   closesocket(sockfd);
#endif
#ifdef LINUX
   close(sockfd);
#endif
  }


  return CHANGE_SUCCEED;
}