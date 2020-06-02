/*
 *  C 개미수열
 */

#include <stdio.h>
#include <stdlib.h>

// 출력용 노드
typedef struct NUM {
    int num;                // 출력 숫자
    struct NUM *next;
} Node;

// 숫자 집계 노드
typedef struct NUM_CNT {
    int num;                // 집계 숫자
    int cnt;                // 집계
    struct NUM_CNT *next;
} MetaNode;

// 리스트 (한 줄의 수열을 표현)
typedef struct NUM_LIST {
    Node *head;             // 출력용 LL (e.i. 수열)
    MetaNode *metaHead;     // 집계용 LL
} List;

// 집계 노드 생성 & 추가
void addMetaNode(List *list, int n) {
    MetaNode *m = (MetaNode*)malloc(sizeof(MetaNode)), *t, *t2;
    m->num = n; m->cnt = 1; m->next = NULL;
    if(list->metaHead) {
        
        // 기존 노드들이 존재하면 오름차순에 맞게 신규 노드 삽입
        if(list->metaHead->num > n) {
            m->next = list->metaHead;
            list->metaHead = m;
        } else {
            for(t = list->metaHead, t2 = t->next; t2; t = t2, t2 = t2->next) {
                if(t->num < n && n < t2->num) {
                    m->next = t2; t->next = m;
                }
            }
            if(!t2 && t->num < n) t->next = m;
        }
    } else {
        list->metaHead = m;
    }
}

// 출력용 노드 생성 & 추가
// 이전에 없던 수를 추가하면 집계 노드 추가 생성
void addNode(List *list, int n) {
    MetaNode *m; int isExists = 0;
    Node *node = (Node*)malloc(sizeof(Node)), *t;
    node->num = n; node->next = NULL;
    if(!(list->head)) {
        list->head = node;
        addMetaNode(list, n);                           // 첫 노드이므로 해당 숫자에 대한 집계 노드 생성
    } else {
        for(m = list->metaHead; m; m = m->next) {
            if(m->num == n) { isExists = 1; break; }    // 신규 추가 숫자가 집계 LL에 있는지 확인
        }
        if(isExists) m->cnt++;                          // 신규 추가 숫자가 집계 LL에 있으면 해당 숫자의 개수를 추가
        else addMetaNode(list, n);                      // 없으면 집계 노드 생성
        for(t = list->head; t->next; t = t->next);
        t->next = node;
    }
}

// 리스트 내 노드 전체 삭제
void deleteList(List *list) {
    Node *n; MetaNode *m;
    while(list->head) {
        n = list->head;
        list->head = list->head->next;
        free(n);
    }
    while(list->metaHead) {
        m = list->metaHead;
        list->metaHead = list->metaHead->next;
        free(m);
    }
}

int main(int ac, char **av) {
    List *lists; int input, i; Node *n; MetaNode * m;

    printf("Enter a #: "); scanf("%d", &input);

    // 각 라인별 리스트 생성 및 초기화
    lists = (List*)malloc(sizeof(List) * input);
    for(i = 0; i < input; i++) {
        lists[i].head = NULL;
        lists[i].metaHead = NULL;
    }

    // 기본값 1 추가
    addNode(&lists[0], 1);

    // 라인별 개미수열 계산
    // 이전 리스트의 집계 LL을 현재 리스트의 출력 LL로 전이
    for(i = 1; i < input; i++) {
        for(m = lists[i - 1].metaHead; m; m = m->next) {
            addNode(&lists[i], m->num);
            addNode(&lists[i], m->cnt);
        }
    }

    // 리스트별 출력용 LL 출력
    for(i = 0; i < input; putchar('\n'), i++) {
        for(n = lists[i].head; n; n = n->next) {
            printf("%d ", n->num);
        }
    }

    // 모든 동적할당 해제
    for(i = 0; i < input; deleteList(&lists[i++])); free(lists);

    return 0;
}