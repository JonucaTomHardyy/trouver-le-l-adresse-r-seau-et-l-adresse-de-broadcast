void decoder_url(char ip[]){
    int nb = strlen(ip);

    for(int i = 0; i <= nb - 1; i++){
        if(ip[i] == '%' && ip[i+1] == '2' && ip[i+2] == 'F'){
            ip[i] = '/';
            ip[i+1] = '/';
            ip[i+2] = '/';
            //printf("%d_ip: %s\n", i, ip);
        }
    }
    //printf("\nip: %s\n", ip);
}