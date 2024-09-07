void valide_ip(Address_Ip address, Address_Ip netmask){
    int k = 0;
    //printf("validation ip/netmask : %ld.%ld.%ld.%ld/%ld.%ld.%ld.%ld\n", address.ip1, address.ip2, address.ip3, address.ip4, netmask.ip1, netmask.ip2, netmask.ip3, netmask.ip4);

    if(0 <= address.ip1 && address.ip1 <= 255       &&       0 <= netmask.ip1 && netmask.ip1 <= 255 && 
       0 <= address.ip2 && address.ip2 <= 255       &&       0 <= netmask.ip2 && netmask.ip2 <= 255 && 
       0 <= address.ip3 && address.ip3 <= 255       &&       0 <= netmask.ip3 && netmask.ip3 <= 255 && 
       0 <= address.ip4 && address.ip4 <= 255       &&       0 <= netmask.ip4 && netmask.ip4 <= 255
    ){
        //printf("<p>ip valide</p><br/>");
        
        if(netmask.ip1 <= 255 && netmask.ip2 <= 255 && netmask.ip3 <= 255){
            for(int i = 0; i <= 8; i++){
                if(netmask.ip4 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

        else if(netmask.ip1 <= 255 && netmask.ip2 <= 255 && netmask.ip4 <= 255){
            for(int i = 0; i <= 8; i++){
                if(netmask.ip3 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

        else if(netmask.ip1 <= 255 && netmask.ip3 <= 255 && netmask.ip4 <= 255){
            for(int i = 0; i <= 8; i++){
                if(netmask.ip2 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

        else if(netmask.ip2 <= 255 && netmask.ip3 <= 255 && netmask.ip4 <= 255){
            for(int i = 0; i <= 8; i++){
                if(netmask.ip1 == (254 + 2*i)){
                    printf("<p>ip et nemask valide</p><br/>");
                    break;
                }
            }
        }

         else{
            printf("<p>netmask non valide</p><br/>");
            printf("<a href=\"ip.html\"></a>");
        }
    }
    else{
        printf("<p>ip ou netmask non valide</p><br/>");
        printf("<a href=\"ip.html\">réentrer une nouvelle netmask</a><br/>");
    }
}
