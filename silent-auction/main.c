#include<stdio.h>
#include<string.h>

int main() {
    int numberOfBids;
    scanf("%d", &numberOfBids);

    int highestBid = 0;
    char highestBidder[100] = "";
     
    for(int i = 0; i < numberOfBids; i++) {
        char bidder[100] = "";
        int bid;
        scanf("%s %d", bidder, &bid);
        if(bid > highestBid) {
            highestBid = bid;
            strcpy(highestBidder, bidder);
        }
    }

    printf("%s", highestBidder);
    return 0;
}
