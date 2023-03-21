#define HUNGRY 1	// 16진수로 표현시 0x01
#define THIRSTY 2	//				  0x02
#define TIRED 4     //				  0x04
#define FIRE 8      //				  0x08
#define COLD 16     //				  0x10
#define POISON 32   //				  0x20
#define POISON2 64  //				  0x40
#define POISON3 128 //				  0x80

// 16진수로 표현시 규칙이 보임

int main()
{
	{
		// int는 4바이트 = 32bit
		// bit 한 칸에 상태이상 하나를 넣는다고 생각할 수 있음
		// 그러면 첫번째 비트(1)는 HUNGRY가 예약을 한다고 가정
		// 두번째 비트(2)는 THIRSTY가 예약
		// 세번째 비트(4)는 TIRED가 예약
		unsigned int iStatus = 0;

		// 배가 고픈상태 + 목이 마른상태
		// 특정 상태를 비트에 넣어주고 싶을 때 비트 합연산(|) 사용
		// 상태 추가
		iStatus |= HUNGRY;
		iStatus |= THIRSTY;

		// 플레이어 상태가 목마른 상태인지 궁금할 때
		// iStatus & THIRSTY << THIRSTY가 있는지 확인
		// 상태 확인
		if (iStatus & THIRSTY)
		{
			// status가 다른 상태를 포함하고 있어도 => 0b101001001010...010 => THIRSTY 상태비트가 1이면
			// THIRSTY = 0b00000000000000000000000000000010 => THIRSTY는 2번째 비트가 1이기 때문에
			// 비트 곱연산하면 2번쨰 비트가 모두 1이기 때문에
			// 그래서 status와 THIRSTY를 곱하면 0b00000000000000000000000000000010 => true가 나옴
			// 만약 status의 THIRSTY 상태비트가 0이면 비트 곱연산은 0이 나오므로 => false가 나옴
		}

		// 플레이어의 특정 상태를 빼고싶음
		if (iStatus &  THIRSTY )
		{
			// XOR은 같으면 0 다르면 1
			// 그치만 XOR은 문제가 발생함 << 없던 상태가 생길수가 있음(둘이 다르면 1이기 때문에)
			// 기존에 HUNGRY가 0비트 였는데 XOR하면 1비트가 되어버림
			// 비트에서 빼기를 할때는 해당 비트를 반전해서 곱해버림
			// 상태 제거
			iStatus &= ~THIRSTY;
		}
	}
	return 0;
}