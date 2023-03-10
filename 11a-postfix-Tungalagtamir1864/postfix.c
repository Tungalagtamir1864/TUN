#include "DS.h"

int is_space(int x)
{
	switch (x)
	{
	case ' ':
	case '\t':
	case '\n':
	case '\r':
	case '\f':
	case '\v':
	case '\0':
		return 1;
	default:
		return 0;
	}
	return 0;
}

int convert_to_int(const char s[])
{
	int len = strlen(s);
	int t = 0, i;
	for (i = 0; i < len; i++)
		t = t * 10 + s[i] - '0';
	return t;
}

void tokenize(const char s[], List *p_list)
{
	char tmp[EQUATION_LENGTH];
	int i, j, k, len;
	j = 0;
	struct Token x;
	len = strlen(s);
	for (i = 0; i <= len; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			/* цифр орж ирлээ */
			tmp[j] = s[i]; // tsipr tempdee hiine
			j++;
		}

		else
		{
			/* тэмдэгт орж ирлээ */
			if (j != 0)
			{ /* Хөрвүүлэх тоо байгаа эсэх */
				tmp[j] = '\0';
				j = 0;
				/* хадгалсан цифрийн цувааг int-рүү хөрвүүл */
				k = convert_to_int(tmp);
				x.flag = 1;
				x.val = k;
				/*
				  Жагсаалтанд x элемнтийг оруулах
				  Жагсаалтын push_back функцыг дуудна
				*/
				l_push_back(p_list, x);
			}
			/*
			  тэмдэгтийг жагсаалтанд оруулах
			  Жагсаалтын push_back функцыг дуудна
			 */
			if (is_space(s[i])) /* хоосон зай, шинэ мөрийг хаяна. */
				continue;

			/*
			  Энд +, -, *, /, (, ) тэмдэгтүүдийг жагсаалтад оруулна.
			 */
			x.flag = 0;
			x.op = s[i];
			l_push_back(p_list, x);
		}
	}

	/* Тэмдэгтэн цуваанаас салгасан тэгшитгэлийг хэвлэх
	   Жагсаалтын print функцыг дуудна.
	 */
	/* l_print(p_list); */
}

/*
  p_token - жагсаалтад байгаа тэгштгэлийг postfix-рүү хөрвүүлнэ
 */
void convert_to_postfix(List *p_token, List *p_post)
{

	Stack *st = malloc(sizeof(Stack));
	st->len = 0;
	st->top = NULL;

	// medeelel hadgalah element variable
	TokenElm *elm = p_token->head;

	while (elm != NULL)
	{
		/////////////////////////////////
		// 1. flag==0;                 //
		//     1.1  len = 0 || op==)
		//     1.2	op == ) 
		//     1.3  op== + -
		//     1.4  op== / * %
		// 2. flag==1;
		/////////////////////////

		if (elm->x.flag == 0)
		{
			// Temdegt buyu operator hadgalna.
			int operator= elm->x.op; // operatortoo temdegtee ogno
			// operator orj irvel shuud
			// stack ruu pushlene.   hooson 40 ( haalt
			if (st->len == 0 || operator== 40)
			{
				s_push(st, operator);
				// stack  ehend orno
			}
			else
			{
				if (operator== 41) // ) baival
				{
					while (st->top->x != 40)
					{
						// ')' baih  ym bol stackd '(' hurtelh buhniig gargaad
						// jagsaaltiin togsgold oruulah ystoi.
						// '(' haaltiig stackaas gargana.
						// stack-d oruulahgui.
						Token token;
						token.flag = 0;				// operator
						token.op = st->top->x;		// temdegtee oruulj ogno
						s_pop(st);					// top element gargana
						l_push_back(p_post, token); // List-д x утгыг төгсгөлд хийнэ  tokengoo list ruu hiine
					}
					s_pop(st); // 40 iigoo gargah
				}
				else
				{
					// yahuuu ????????????????????
					// f gar gar hohine hicheeldee tamii guuuy ^_^

					// adilhan erembetei
					if (operator== '-' || operator== '+')
					{ 
						while (st->len > 0 && st->top->x != 40)
						{
							// umnuhtei adil
							Token token;
							token.flag = 0;
							token.op = st->top->x;
							// stackaas gargaad
							s_pop(st);
							// tokenoo oruulah
							l_push_back(p_post, token);
						}
						// stack ruu operatoroo pushlene
						s_push(st, operator);
					}
					else
					{
						if (st->top->x == '/' || st->top->x == '*' || st->top->x == '%')
						{
							Token token;
							token.flag = 0;
							token.op = st->top->x;
							s_pop(st);
							l_push_back(p_post, token);
						}
						s_push(st, operator);
					}
				}
			}
		}
		else
		{
			l_push_back(p_post, elm->x);
		}
		// daraagiin element ruu ochih
		elm = elm->next;
	}
	while (st->len)
	{
		Token token;
		token.flag = 0;
		token.op = st->top->x;
		s_pop(st);
		l_push_back(p_post, token);
	}
}

int solve(List *p_post)
{
	Stack *st = malloc(sizeof(Stack));
	st->len = 0;
	st->top = NULL;
	int sol;
	int m, n;
	// Initialize hiigeed
	// Tokenooroo guine.
	TokenElm *elm = p_post->head;

	while (elm != NULL)
	{
		if (elm->x.flag == 1)
		{
			// hervee elm ni too baival shuud pushlene
			s_push(st, elm->x.val);
		}
		else
		{
			// operator baih ym bol hamgiin suuld orson operandoo avna
			m = st->top->x; 
			s_pop(st); 

			n = st->top->x; // n dee daraagiin elementee ogno
			s_pop(st);

			if (elm->x.op == '+')
			{
				sol = n + m;
			}
			else if (elm->x.op == '-')
			{
				sol = n - m;
			}
			else if (elm->x.op == '*')
			{
				sol = n * m;
			}
			else if (elm->x.op == '/')
			{
				sol = n / m;
			}
			else if (elm->x.op == '%')
			{
				sol = n % m;
			}
			// ur dungee stack ruu oruulna
			s_push(st, sol);
		}
		// daraachiin token ruu shiljine
		elm = elm->next;
	}
	return sol;
}
