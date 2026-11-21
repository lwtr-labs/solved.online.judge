#include <stdio.h>
#define MAX_SIZE 1000

struct Queue {
    int list[MAX_SIZE];
    int front; int back; int count;
};

void InitQ(struct Queue* queue) {
    queue->front = 0; queue->back = 0; queue->count = 0;
}

void PushQ(struct Queue* queue, int input) {
    queue->count++;
    queue->list[queue->back++] = input;
}

int PopQ(struct Queue* queue) {
    queue->count--;
    return queue->list[queue->front++];
}

int main(void) {
    int n, m, idx, input, temp, max, spend;
    
    struct Queue queue;
    
    scanf("%d", &n);
    
    int i, j, k;
    for(i = 0; i < n; i++) {
        scanf(" %d %d", &m, &idx);
        InitQ(&queue);
        spend = 0;
        
        for(j = 0; j < m; j++) {
            scanf(" %d", &input);
            PushQ(&queue, input);
        }
        
        while(1) {
            max = 0;
            for(int j = 1; j < queue.count; j++)
                max = queue.list[queue.front + j] > max ? queue.list[queue.front + j] : max;
            
            if(queue.front == idx && queue.list[queue.front] < max) {
                temp = PopQ(&queue);
                PushQ(&queue, temp);
                idx = queue.back - 1;
            } else if(queue.front == idx && queue.list[queue.front] >= max) {
                spend += 1;
                printf("%d\n", spend);
                break;
            } else {
                if(queue.list[queue.front] < max) {
                    temp = PopQ(&queue);
                    PushQ(&queue, temp);
                } else {
                    PopQ(&queue);
                    spend += 1;
                }
            }
        }
    }
    return 0;
} 