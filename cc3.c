typedef int TElement;

typedef struct noeud{
    TElement donnee;
    struct noeud *fg,*fd;
}*Arbre;

int occElt(TElement elt, Arbre a){
    int cpt=0;
    if(a==NULL){
        return 0;
    }
    if(a->donnee==elt){
        return 1+occElt(elt,a->fg)+occElt(elt,a->fd);
    }
    
}

int estEquilibre(Arbre a){
    if(a==NULL){
        return 0;
    }
    int cpp=0;
    int cpi=0;

    if((a->donnee)%2==0){
        cpp++;
    }else cpi++;

    occElt(a->fg);
    occElt(a->fd);

    return (cpp==cpi) ? 1 : 0;
}

int estEquilibre (Arbre a){
    if(a==NULL){
        return 0;
    }
    
    int cpp=0;
    int cpi=0;

    if((a->donnee)%2==0){
        return cpp+=1+estEquilibre(a->fg)+estEquilibre(a->fd);
    }else{
        return cpi+=1+estEquilibre(a->fg)+estEquilibre(a->fd);
    }

    return (cpp==cpi) ? 1:0;
}

Arbre creatFeuille(TElement elt){
    Arbre a= NULL;
    a=(Arbre)malloc(sizeof(struct noeud *));
    a->donnee=elt;
    a->fg=NULL;
    a->fd=NULL;
    return a;
}

Arbre creatNoeud(TElement elt, Arbre fg, Arbre fd){
    a=creatFeuille(elt);
    a->fg=fg;
    a->fd=fd;
    return a;
}

void main(){
    Arbre a=NULL;
    Arbre f5=creatFeuille(5);
    Arbre f10=creatFeuille(10);
    Arbre f9=creatNoeud(9,f5,f10);
    a=creatNoeud(9,NULL,f9);

    int occ=occElt(a);
    printf("Nombre d'occurence de la valeur dans l'arbre: %d",occ);
}