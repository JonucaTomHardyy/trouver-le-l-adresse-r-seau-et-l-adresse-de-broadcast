typedef struct {
    unsigned long ip1;
    unsigned long ip2;
    unsigned long ip3;
    unsigned long ip4;
}Address_Ip;

/* prototype */

void start(char titre[], char css[]);
void end();

void copy_ip(Address_Ip *address, Address_Ip *netmask, char ip[], int *nb_bits);

void valide_ip(Address_Ip address, Address_Ip netmask);

void binaire_struct(Address_Ip *bit_ip);

void sortit(Address_Ip address, Address_Ip netmask, Address_Ip bit_ip, Address_Ip bit_net, int nb_bits);

void octet(unsigned long *bit);

void nb_bit(Address_Ip netmask, Address_Ip bit_net, int *nb_bits);

void decoder_url(char ip[]);