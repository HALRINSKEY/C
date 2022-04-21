#include<stdio.h>
#include<string.h>
int main(void){

    char board[6][6];
    int count = 1;
	int flag;


//ボード作成
	for(int y = 0; y < 6; y++){
		for(int x = 0; x < 6; x++){
			board[y][x] = ' ';
		}
	}

	for(int y = 1; y < 6; y++){
		board[y][1] = '#';
		board[y][5] = '#';
	}

	for(int x = 1; x < 6; x++){
		board[1][x] = '#';
		board[5][x] = '#';
	}

	for(int x = 2; x < 5; x++){
		board[0][x] = 47 + x;  //ascii 1 = 49, 2 = 50, 3 = 51
	}

	for(int y = 2; y < 5; y++){
		board[y][0] = 95 + y;  //ascii a = 97, b = 98, c = 99
	}

    printf("1st:player1 is o  2nd:player2 is x\n\n");

//出力

    for(int y = 0; y < 6; y++){
    	for(int x = 0; x < 6; x++){

    		printf("%c",board[y][x]);

    		}

    	printf("\n");

    }


    while(1){

		char point[10];
		printf("座標を入力してください。(例 a1)\n");
        scanf("%s", point);
        count += 1;

 	  	printf("\x1b[2J");

        if(count % 2 == 0){

            if     (strcmp(point , "a1") == 0){ board[2][2] = 'o' ;}
            else if(strcmp(point , "a2") == 0){ board[2][3] = 'o' ;}
            else if(strcmp(point , "a3") == 0){ board[2][4] = 'o' ;}
            else if(strcmp(point , "b1") == 0){ board[3][2] = 'o' ;}
            else if(strcmp(point , "b2") == 0){ board[3][3] = 'o' ;}
            else if(strcmp(point , "b3") == 0){ board[3][4] = 'o' ;}
            else if(strcmp(point , "c1") == 0){ board[4][2] = 'o' ;}
            else if(strcmp(point , "c2") == 0){ board[4][3] = 'o' ;}
            else if(strcmp(point , "c3") == 0){ board[4][4] = 'o' ;}
			else{
					printf("無効な座標です。\n");
					count -= 1;
				}

        }

        else{

            if     (strcmp(point , "a1") == 0){ board[2][2] = 'x' ;}
            else if(strcmp(point , "a2") == 0){ board[2][3] = 'x' ;}
            else if(strcmp(point , "a3") == 0){ board[2][4] = 'x' ;}
            else if(strcmp(point , "b1") == 0){ board[3][2] = 'x' ;}
            else if(strcmp(point , "b2") == 0){ board[3][3] = 'x' ;}
            else if(strcmp(point , "b3") == 0){ board[3][4] = 'x' ;}
            else if(strcmp(point , "c1") == 0){ board[4][2] = 'x' ;}
            else if(strcmp(point , "c2") == 0){ board[4][3] = 'x' ;}
            else if(strcmp(point , "c3") == 0){ board[4][4] = 'x' ;}
			else{
					printf("無効な座標です。\n");
					count -= 1;
				}
        }







    	for(int y = 0; y < 6; y++){
    		for(int x = 0; x < 6; x++){

    			printf("%c",board[y][x]);

    			}

    		printf("\n");

    	}

 //勝敗判定

        //横の判定
        for(int y = 2; y < 5; y++){

            if(board[y][2] == 'o' && board[y][3] == 'o'&& board[y][4] == 'o'){
                printf("player1 win!\n");
				flag = 1;
                break;
            }

            else if(board[y][2] == 'x' && board[y][3] == 'x'&& board[y][4] == 'x'){
                printf("player2 win!\n");
				flag = 1;
                break;
            }

        }

        //縦の判定
        for(int x = 2; x < 5; x++){

            if(board[2][x] == 'o' && board[3][x] == 'o'&& board[4][x] == 'o'){
                printf("player1 win!\n");
				flag = 1;
                break;
            }

            else if(board[2][x] == 'x' && board[3][x] == 'x'&& board[4][x] == 'x'){
                printf("player2 win!\n");
				flag = 1;
                break;
            }

        }

        //斜めの判定
        if(board[2][2] == 'o' && board[3][3] == 'o'&& board[4][4] == 'o'){
            printf("player1 win!\n");
            break;
        }

        else if(board[2][2] == 'x' && board[3][3] == 'x'&& board[4][4] == 'x'){
            printf("player2 win!\n");
            break;
        }

        else if(board[2][4] == 'o' && board[3][3] == 'o'&& board[4][2] == 'o'){
            printf("player1 win!\n");
            break;
        }

        else if(board[2][4] == 'x' && board[3][3] == 'x'&& board[4][2] == 'x'){
            printf("player2 win!\n");
            break;
        }

		if(flag == 1){
			break;
		}


	}


	return(0);

}
