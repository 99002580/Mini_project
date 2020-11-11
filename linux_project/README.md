# pizza order management
pizza is ordered using the concept of message queue,semophore and mutex so
that pizza can be processed one after the other and delivered to the customer
#how to check
Type "make all" in one terminal you can see compilation of se and re as below
gcc sem_send.c -o se -lpthread
gcc sem_receive.c -o re -lpthread

type "ls" to check se and re are generated
open one terminal and type ./se and give your inputs
parallelly open another terminal and type ./re and check whether data is
received or not

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/bd75b6b1df4a48b281e89d5dacc6e38f)](https://www.codacy.com/gh/99002580/Mini-project/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=99002580/Mini-project&amp;utm_campaign=Badge_Grade)
