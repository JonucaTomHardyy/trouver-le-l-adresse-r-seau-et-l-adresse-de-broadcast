void copy_ip(Address_Ip *address, Address_Ip *netmask, char ip[], int *nb_bits){
    char ip1[4], ip2[4], ip3[4], ip4[4], net1[4], net2[4], net3[4], net4[4];
    int nb_zero = 0, nb_sscanf = 0, nb_1 = 0;

    nb_sscanf = sscanf(ip, "ip///netmask=%[^.].%[^.].%[^.].%[^///]///%[^.].%[^.].%[^.].%s", ip1, ip2, ip3, ip4, net1, net2, net3, net4);
    //printf("<p>nb_sscanf= %d<br/></p>", nb_sscanf);

    if(nb_sscanf == 5){
        //printf("1<br/><br/>");
        *nb_bits = atoi(net1);
        nb_1 = *nb_bits;
        //printf("nb_1 = %d<br/>", nb_1);
        //printf("nb_bits = %d<br/>",*nb_bits);

        address->ip1 = atoi(ip1);
        address->ip2 = atoi(ip2);
        address->ip3 = atoi(ip3);
        address->ip4 = atoi(ip4);

        netmask->ip1 = 0;
        netmask->ip2 = 0;
        netmask->ip3 = 0;
        netmask->ip4 = 0;

        if(*nb_bits < 8 && *nb_bits > 0){
            

            for(int i = 1; i <= 8; i++){
                if(i <= nb_1){
                    netmask->ip1 = netmask->ip1 * 10 + 1;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip1);
                }
                else{
                    netmask->ip1 = netmask->ip1 * 10;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip1);
                }
            }

            octet(&netmask->ip1);
            //printf("netmask = %ld<br/>", netmask->ip1);

            netmask->ip2 = 0;
            netmask->ip3 = 0;
            netmask->ip4 = 0;
        }
        else if(*nb_bits < 16 && *nb_bits >= 8){
            nb_1 = nb_1 - 8;

            netmask->ip1 = 255;

            for(int i = 1; i <= 8; i++){
                if(i <= nb_1){
                    netmask->ip2 = netmask->ip2 * 10 + 1;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip2);
                }
                else{
                    netmask->ip2 = netmask->ip2 * 10;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip2);
                }
            }

            octet(&netmask->ip2);
            //printf("netmask = %ld<br/>", netmask->ip2);

            netmask->ip3 = 0;
            netmask->ip4 = 0;

        }

        else if(*nb_bits < 24 && *nb_bits >= 16){
            nb_1 = nb_1 - 8*2;

            netmask->ip1 = 255;
            netmask->ip2 = 255;

            for(int i = 1; i <= 8; i++){
                if(i <= nb_1){
                    netmask->ip3 = netmask->ip3 * 10 + 1;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip3);
                }
                else{
                    netmask->ip3 = netmask->ip3 * 10;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip3);
                }
            }

            octet(&netmask->ip3);
            //printf("netmask = %ld<br/>", netmask->ip3);

            netmask->ip4 = 0;
        }

        else if(*nb_bits < 32 && *nb_bits >= 24){
            nb_1 = nb_1 - 8*3;

            netmask->ip1 = 255;
            netmask->ip2 = 255;
            netmask->ip3 = 255;

            for(int i = 1; i <= 8; i++){
                if(i <= nb_1){
                    netmask->ip4 = netmask->ip4 * 10 + 1;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip4);
                }
                else{
                    netmask->ip4 = netmask->ip4 * 10;
                    //printf("i = %d  netmask = %ld<br/>", i, netmask->ip4);
                }
            }

            octet(&netmask->ip4);
            //printf("netmask = %ld<br/>", netmask->ip4);
        }
    }
    else if(nb_sscanf == 8){
        //printf("2<br/><br/>");
        //printf("ip= %s\nip1= %s ip2= %s ip3= %s ip4= %s /\nnet1= %s net2= %s net3= %s net4= %s\n", ip, ip1, ip2, ip3, ip4, net1, net2, net3, net4);

        address->ip1 = atoi(ip1);
        address->ip2 = atoi(ip2);
        address->ip3 = atoi(ip3);
        address->ip4 = atoi(ip4);

        netmask->ip1 = atoi(net1);
        netmask->ip2 = atoi(net2);
        netmask->ip3 = atoi(net3);
        netmask->ip4 = atoi(net4);

        //printf("\naddress->ip1= %d address->ip2= %d address->ip3= %d address->ip4= %d/", address->ip1, address->ip2, address->ip3, address->ip4);
        //printf("nemask->ip1= %d nemask->ip2= %d nemask->ip3= %d nemask->ip4= %d\n\n", netmask->ip1, netmask->ip2, netmask->ip3, netmask->ip4);
    }
    else{
        printf("<p>il y a erreur lors de la copy dans le structure</p>\n");
        printf("<p>ip = %s</p>\n", ip);
        printf("<a href=\"ip.html\">réentrer une nouvelle netmask</a><br/>");
    }
    //printf("nb_bits = %d<br/>", *nb_bits);
}