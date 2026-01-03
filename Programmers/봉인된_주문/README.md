# 봉인된 주문

https://school.programmers.co.kr/learn/courses/30/lessons/389481

1. Make a String -> Number, Number -> String Conversion.

2. Sort the ban words ascending, and increment n if ban word is less or equal to
   n.

### Conversion

Alphabet can be converted by using base-26.

ex) abc: 'a' _ 26^2 + 'b' _ 26^1 + 'c' \* 26^

```
ll res = 0;
for(int i=0; i<s.length(); i++){
    res *= 26;
    res += s[i] - 'a' + 1;
}
```

However, since zero is not available, numbers should be converted to string
starting from the lower digit and reverse.

```
while(n > 0){
    // Edge case : z
    if(n % 26 == 0){
        s += 'z';
        n -= 26;
    }
    else{
        s += (char)((n % 26) - 1 + 'a');
        n -= n % 26;
    }
    n /= 26;
}
reverse(s.begin(), s.end());
```
