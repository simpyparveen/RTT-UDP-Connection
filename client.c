//
//
//  
//
//  Created by Simpy on 2019-03-07.
/* https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_73/apis/gettod.htm

 client.c -- a datagram "client" demo
 Usage :
    gcc client.c -o client
 
 Run : ./client Server-IP Sending-Message
    ./client 127.0.0.1 ClientHello
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <math.h>
#include <sys/time.h> //Time header added
#include "itoa.c"  //added file
#define SERVERPORT "49510"    // the port users will be connecting to
#define MAXBUFLEN 100


int main(int argc, char *argv[])
{
    FILE * fPtr;//File
    
    for (int i=0; i<100; i++){
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;//stores the server address
    int rv;
    int numbytes;
    char buf[MAXBUFLEN];
     struct timeval tvalBefore, tvalAfter; //Time parameters added
    
     socklen_t addr_len;
    if (argc != 3) {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    
        if ((rv = getaddrinfo(argv[1], SERVERPORT, &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    
    // loop through all the results and make a socket
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("talker: socket");
            continue;
        }
        
        break;
    }
    
    if (p == NULL) {
        fprintf(stderr, "talker: failed to create socket\n");
        return 2;
    }
    
    
    /*** Start Time recorded ***/
    gettimeofday (&tvalBefore, NULL);
    /*** ***/
    
    if ((numbytes = sendto(sockfd, argv[2], strlen(argv[2]), 0,
                           p->ai_addr, p->ai_addrlen)) == -1) {
        perror("talker: sendto");
        exit(1);
    }
    addr_len = sizeof their_addr;
    printf("\nClient waits...\n");
    int recvlen = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0, (struct sockaddr *)&their_addr,&addr_len);

    /*** End Time recorded ***/
    gettimeofday (&tvalAfter, NULL);
      /***  ***/
    
    
    buf[numbytes] = '\0';
    printf("listener: packet contains %d \"%s\"\n",recvlen, buf);
    
    
      /*** RTT calculation ***/
    
    long result = ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L+tvalAfter.tv_usec) - tvalBefore.tv_usec;
    printf("Time in microseconds: %ld microseconds\n",result);
    
   
    
    printf("Printing to file");
    fPtr = fopen("file1.txt", "a");
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        //exit(EXIT_FAILURE);
    }
    char sresult[255];
    
    // convert 123 to string [buf]
    itoa(result, sresult, 10);//decimal to string
    printf("\n %s : ",sresult);
    /*int len = strlen(sresult);
    printf("Length is %d \n",len);
    sresult[len]='\0';*/
   // printf("\n %s : ",sresult);
    fputs(sresult, fPtr);
   fputs("\n",fPtr);
    /* Close file to save file data */
   
    
     fclose(fPtr);
     close(sockfd);
    }
    return 0;
}
