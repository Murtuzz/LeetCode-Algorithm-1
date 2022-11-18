class Solution:
def isUgly (self, n: int) -> bool:
flag = True;
if (n < 1): flag = False
elif (n > 1):
sqrt_num = ceil(math.sqrt(n)) + 1
for num in range(2, sqrt_num) :
return flag
-------------------------------------------------------------
class Solution {
public:
bool isUgly(int n) {
bool flag = true;
if (n < 1) flag = false;
else if (n > 6) {
for ( int i = 7; i <= n / 2; i++) {
if (n % i == 0) {
int sqrt_n = sqrt (i);
bool flag_p = true;
for ( int j = 2; j < sqrt_n; j++) {
if (sqrt_n % j == 0) {
flag_p = false;
break;
}
}
if (flag_p) {
flag = false;
break;
}
}
}
}
return flag;
}
};