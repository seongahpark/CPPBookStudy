# Week 4 - 질문 정리

#### 성아

1. RCSP의 특징을 말해보시오

   > - 어떤 자원을 가리키는 외부 객체의 개수
   >
   > - 개수가 0이되면 해당 자원을 자동으로 삭제
   >
   > - 참조 상태가 고리를 이루면 없앨 수 없다 (ex. 두 객체가 서로를 가리킴) 
   >
   > - 대표적인 RCSP : tr1::shared_ptr

2. 객체 복사 함수를 직접 구현 할 때 고려해야 할 점 

   > 1. 복사 금지
   > 2. 관리하고 있는 자원에 대한 참조 카운팅 -> shared_ptr
   > 3. 관리하고 있는 자원 복사
   > 4. 관리하고 있는 자원의 소유권 옮김 -> auto_ptr 

3. 배열 자원을 동적 할당할 경우 delete에서 []를 사용하지 않을 경우 어떤 문제가 발생하는가?

   > delete 연산자가 적용되는 객체 = 소멸자가 호출되는 횟수를 뜻하기 때문에 모든 배열이 소멸되지 않는 문제가 발생하여 미정의 동작으로 이어질 가능성이 있다. 따라서 new에서 []로 해줬으면 delete에서도 []해줘야 함

<br>

#### 현준

1. 


<br>

#### 재현

1. 
