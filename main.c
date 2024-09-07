#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "main.h"
#include "copy_ip.c"
#include "valide_ip.c"
#include "binaire_struct.c"
#include "octet.c"
#include "nb_bit.c"
#include "decoder_url.c"
#include "sortit.c"


int main(){
    printf("content_type: text/html\n\n");

    start("ADRESS IP", "ip.css");

    Address_Ip address, netmask, bit_ip, bit_net;
    char *ip = NULL;
    int class = 0, nb_bits = 0;

    ip = getenv("QUERY_STRING");

    decoder_url(ip);
    //printf("<p>ip : %s<br/></p>", ip);

    copy_ip(&address, &netmask, ip, &nb_bits);
    copy_ip(&bit_ip, &bit_net, ip, &nb_bits);


    printf("<p>address.ip / netmask.ip = %ld.%ld.%ld.%ld / %ld.%ld.%ld.%ld</p>", address.ip1, address.ip2, address.ip3, address.ip4, 
                                                                               netmask.ip1, netmask.ip2, netmask.ip3, netmask.ip4);


    valide_ip(address, netmask);


    binaire_struct(&bit_ip);
    printf("<p>ip: %ld.%ld.%ld.%ld  ---> %ld.%ld.%ld.%ld</p>\n",address.ip1, address.ip2, address.ip3, address.ip4, bit_ip.ip1, bit_ip.ip2, bit_ip.ip3, bit_ip.ip4);

    binaire_struct(&bit_net);
    printf("<p>netmask: %ld.%ld.%ld.%ld  ---> %ld.%ld.%ld.%ld</p>\n",netmask.ip1, netmask.ip2, netmask.ip3, netmask.ip4, bit_net.ip1, bit_net.ip2, bit_net.ip3, bit_net.ip4);


    sortit(address, netmask, bit_ip, bit_net, nb_bits);


    end();
    
    return 0;
}

void start(char titre[], char css[]){
    //printf("content_type: text/html\n\n");

    printf("<!DOCTYPE html>\n");
    printf("<HTML>\n");
    printf("\t<HEAD>\n");
    printf("\t\t<TITLE>%s</TITLE>\n",titre);
    printf("\t\t<META charset=\"utf-8\">\n");
    printf("<LINK REL=\"STYLESHEET\" HREF=\"%s\">", css);
    printf("\t</HEAD>\n");
    printf("\t<BODY>\n");
}

void end(){
    printf("\t</BODY>\n");
    printf("</HTML>\n");
}