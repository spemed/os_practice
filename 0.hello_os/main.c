//
// Created by bytedance on 2021/5/22.
//


//彭东 @ 2021.01.09
void _strwrite(char* string)
{
    char* p_strdst = (char*)(0xb8000);//指向显存的开始地址
    while (*string)
    {
        *p_strdst = *string++;
        p_strdst += 2;
    }
    return;
}

void printf(char* fmt, ...)
{
    _strwrite(fmt);
    return;
}


int main() {
    printf("yangruiyang os");
    return 0;
}