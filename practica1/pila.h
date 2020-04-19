#include"elem.h"

typedef struct p{

    elem data;
    struct p*sig;

}*stack;

stack empty(void){
    return NULL;
}
int isEmpty(stack p){
    return p == NULL;
}

stack push(elem e, stack p){
    stack neww;

    neww = (stack)malloc(sizeof(struct p));
    neww ->data = e;
    neww ->sig  = p;

    return neww;
}


elem top(stack p){
    return p ->data;
}

stack pop(stack p){
    return p ->sig;
}


char * inapos(char *ex){

   
    char *regularEx = (char*)malloc(50*sizeof(char));
    stack p = empty();
    char c;
    int i = 0;


    while(*ex){

        c = *ex;


        if(es_parIz(c)){
            p = push(c,p);
        }
        else{

            if(es_parDer(c)){

                while(!es_parIz(top(p))){
                    //impElem(top(p));
                    regularEx[i] = top(p);
                    i++;
                    p = pop(p);
                }

                p = pop(p); // sacamos el ( que sobre
            }

            else{

                if(esop(c)){
                    
                    //printf("operador que entra a el if %c\n",c);
                    if(isEmpty(p) || (priori_op(c) > priori_op(top(p)))){
                        //printf("if operador lo que meto a la pila : %c\n",c);
                        p = push(c,p);
                    }

                    else{


                        while(!isEmpty(p) && (priori_op(c) <= priori_op(top(p)))){

                            //impElem(top(p));
                            regularEx[i] = top(p); 
                            i++; 
                            p = pop(p);

                            
                        }

                        
                     
                    }

                }


                else{
                    
                    //impElem(c);
                    regularEx[i] = c;
                    i++;

                }
            }
        }

        ex++;
    }

    if(!isEmpty(p)){
        //impElem(top(p));
        regularEx[i] = top(p);
        i++;
        p = pop(p);
    }

    return regularEx;

}