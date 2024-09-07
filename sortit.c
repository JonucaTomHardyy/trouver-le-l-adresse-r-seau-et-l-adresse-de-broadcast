void sortit(Address_Ip address, Address_Ip netmask, Address_Ip bit_ip, Address_Ip bit_net, int nb_bits){
    Address_Ip ad_r, ad_b;
    int nb_zero = 0, k = 0, nb_1 = nb_bits;
        printf("1_nb_1 = %d<br/>", nb_1);
    
    if(0 < nb_bits && nb_bits <= 8){
        printf("1<br/>");
    /* adresse reseau */
        nb_1 = 8 - nb_1;
        nb_zero = pow(10, nb_1);
        ad_r.ip1 = bit_ip.ip1 / nb_zero;
        ad_r.ip1 = ad_r.ip1 * nb_zero;
        octet(&ad_r.ip1);

        ad_r.ip2 = 0;
        ad_r.ip3 = 0;
        ad_r.ip4 = 0;


    /* adresse brodcast */
        ad_b.ip1 = ad_r.ip1;
        ad_b.ip2 = 255;
        ad_b.ip3 = 255;
        ad_b.ip4 = 255;

        
    }

    else if(8 < nb_bits && nb_bits < 16){
        //printf("2<br/>");
    /* adresse reseau */
        ad_r.ip1 = address.ip1;

        nb_1 =  nb_1 - 8;
        nb_1 = 8 - nb_1;
        nb_zero = pow(10, nb_1);
        ad_r.ip2 = bit_ip.ip2 / nb_zero;
        ad_r.ip2 = ad_r.ip2 * nb_zero;
        octet(&ad_r.ip2);

        ad_r.ip3 = 0;
        ad_r.ip4 = 0;


    /* adresse brodcast */
        ad_b.ip1 = address.ip1;
        ad_b.ip2 = 255 - netmask.ip2;
        ad_b.ip3 = 255;
        ad_b.ip4 = 255;
    }

    else if(16 <= nb_bits && nb_bits < 24){
        //printf("3<br/>");
    /* adresse reseau */
        ad_r.ip1 = address.ip1;
        ad_r.ip2 = address.ip2;

        nb_1 = nb_1 - 16;
        nb_1 = 8 - nb_1;
        nb_zero = pow(10, nb_1);
        ad_r.ip3 = bit_ip.ip3 / nb_zero;
        ad_r.ip3 = ad_r.ip3 * nb_zero;
        octet(&ad_r.ip3);

        ad_r.ip4 = 0;


    /* adresse brodcast */
        ad_b.ip1 = address.ip1;
        ad_b.ip2 = address.ip2;
        ad_b.ip3 = 255 - netmask.ip3;
        ad_b.ip4 = 255;
    }

    else if(24 <= nb_bits && nb_bits < 32){
        //printf("4<br/>");
    /* adresse reseau */
        ad_r.ip1 = address.ip1;
        ad_r.ip2 = address.ip2;
        ad_r.ip3 = address.ip3;

        nb_1 = nb_1 - 24;
        nb_1 = 8 - nb_1;
        printf("nb_1 = %d", nb_1);
        nb_zero = pow(10, nb_1);
        ad_r.ip4 = bit_ip.ip4 / nb_zero;
        ad_r.ip4 = ad_r.ip4 * nb_zero;
        octet(&ad_r.ip4);


    /* adresse brodcast */
        ad_b.ip1 = address.ip1;
        ad_b.ip2 = address.ip2;
        ad_b.ip3 = address.ip3;
        ad_b.ip4 = 255 - netmask.ip4;        
    }

    printf("<p>adresse reseau: @R= %ld.%ld.%ld.%ld<br/>\nadresse de broadcast: @B= %ld.%ld.%ld.%ld</p>\n", ad_r.ip1, ad_r.ip2, ad_r.ip3, ad_r.ip4, ad_b.ip1, ad_b.ip2, ad_b.ip3, ad_b.ip4);
}