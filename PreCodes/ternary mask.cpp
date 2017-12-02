int three[sz]; // here sz is 3^something dile oi something tai sz

void init(){
    int i;
    three[0] = 1;
    for(i=1;i<10;i++)
        three[i] = 3 * three[i-1];
}

int get_bit(int mask, int pos){
    return (mask / three[pos]) % 3;
}

int set_bit(int mask, int pos, int bit){
    int tmp =(mask / three[pos]) % 3;
    mask -= tmp * three[pos];
    mask += bit * three[pos];
    return mask;
}
