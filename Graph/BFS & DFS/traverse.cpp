#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <semaphore.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <sstream>
#include <iostream>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include "traverse.h"
using namespace std;


int main(){
	int v, e;
	cin >> v >> e;
	int x,y;

	for(int i = 0;i < e; i++){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}
/*
	//level
	int k;
	cin >> k;
	int c = bfs(0,k, v);
	printf("%d\n",c);
*/
	dfs(0);
	int s = 0;
	int f = 5;
	printPath(s,f);



	return 0;
}
/*
9 11
0 8
8 4
0 3
3 4
3 2
0 1
1 7
1 2
2 7
2 5
5 6
*/



