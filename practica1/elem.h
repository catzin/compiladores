typedef char elem;

void impElem(elem e){
    printf("%c",e);
}

int es_Operan(elem e){
    return (e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z')||(e >='0'&& e <='9');
}
int es_parIz(elem e){
    return e == '(';
}

int es_parDer(elem e){
    return e == ')';
}
int esop(elem e){

    switch(e){

        case '+':return 1;break;
        case '*':return 1;break;
        case '|':return 1;break;
        case ':':return 1;break;
        default:return 0;break;
    }  
}

int priori_op(elem e){
    int op = 0;

    switch(e){
        case '+':op = 3;break;
        case '*':op = 3;break;
        case ':':op = 1;break;
        case '|':op = 2;break;
        case '(':op = 0;break;
        case ')':op = 0;break;     
    }

    return op;
}
