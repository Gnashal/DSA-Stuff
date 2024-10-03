String* getNames(PersonOpenDict d, String city) {
    String temp[100];
    int index = 0, pos;
    NodePtr trav = NULL;
    for (int i = 1; i <= 100; ++i) {
        pos = hash(i);
        trav = d.list[pos];
        while (trav!= NULL) {
            if (trav->p.id == i && strcmp(trav->p.add.city, city) == 0 ) {
                strcpy(temp[index++] ,trav->p.name);
            }
            trav = trav->link;
        }   
    }
    strcpy(temp[index++] ,"");
    String* names = mallco(sizeof(String) * index);
    if (names) {
        memcpy(names, temp, sizeof(String) * index);
    }

    return names;
}





void stackToQueue(StackLList* s, QueuePersonLList* q) {
    PersonCloseDict cd;
    for (int i = 0; i < cd.max; ++i) {
        cd.list[i].id = -1;
    }
    int pos;
    StackLList temp = NULL;
    NodePtr holder = NULL;
    while(*s != NULL) {
        pos = hash ((*s)->p.id);
        if (cd.list[pos].id == -1 || cd.list[pos].id == -2)  {
            cd.list[pos] = (*s)->p;
            NodePtr newNode = malloc(sizeof(NodeType));
            newNode->p = (*s)->p;
            newNode = &(q->tail);
            if (q->head == NULL && q->tail == NULL) {
                q->head = newNode;
                q->tail = newNode;
                q->tail = q->tail->link;
            } else {
                q->tail = newNode;
            }
        } else {
            continue;
        }
        holder = *s;
        (*s)->link = holder;
        *s = holder->link;
        holder->link = temp;
        temp = holder;
    }
    // Building up orig stack
    while (temp != NULL){
        holder = temp;
        *s = temp->link;
        holder->link = *s;
        *s = holder;
    }
}