
void ft_print_combn(int n)
{
	int	chiffre_zero;
	int	chiffre_neuf;
	int a = 57;
	int	b = 57;
	int	c = 57;
	int	d = 57;
	int	e = 57;
	int	f = 57;
	int	g = 57;
	int	h = 57;
	int	i = 57;
	
	chiffre_zero = 48;
	chiffre_neuf = 57;	
	if(n == 1)
		a = chiffre_zero;
	if(n == 2)
		{
			a = (chiffre_zero + 1);
			b = chiffre_zero;
		}
	if(n == 3)
		{
			a = (chiffre_zero + 2);
			b = (chiffre_zero + 1);
			c = chiffre_zero;
		}
	if(n == 4)
		{
			a = (chiffre_zero + 3);
			b = (chiffre_zero + 2);
			c = (chiffre_zero + 1);
			d = chiffre_zero;
		}
	if(n == 5)
		{
			a = (chiffre_zero + 4);
			b = (chiffre_zero + 3);
			c = (chiffre_zero + 2);
			d = (chiffre_zero + 1);
			e = chiffre_zero;
		}
	if(n == 6)
		{
			a = (chiffre_zero + 5);
			b = (chiffre_zero + 4);
			c = (chiffre_zero + 3);
			d = (chiffre_zero + 2);
			e = (chiffre_zero + 1);
			f = chiffre_zero;
		}
	if(n == 7)
		{
			a = (chiffre_zero + 6);
			b = (chiffre_zero + 5);
			c = (chiffre_zero + 4);
			d = (chiffre_zero + 3);
			e = (chiffre_zero + 2);
			f = (chiffre_zero + 1);
			g = chiffre_zero;
		}
	if(n == 8)
		{
			a = (chiffre_zero + 7);
			b = (chiffre_zero + 6);
			c = (chiffre_zero + 5);
			d = (chiffre_zero + 4);
			e = (chiffre_zero + 3);
			f = (chiffre_zero + 2);
			g = (chiffre_zero + 1);
			h = chiffre_zero;
		}
	if(n == 9)
		{
			a = (chiffre_zero + 8);
			b = (chiffre_zero + 7);
			c = (chiffre_zero + 6);
			d = (chiffre_zero + 5);
			e = (chiffre_zero + 4);
			f = (chiffre_zero + 3);
			g = (chiffre_zero + 2);
			h = (chiffre_zero + 1);
			i = chiffre_zero;
		}
	while (i <= chiffre_neuf)
		{
			while (h <= chiffre_neuf)
				{
					while (g <= chiffre_neuf)
						{
							while (f <= chiffre_neuf)
								{
									while (e <= chiffre_neuf)
										{
											while (d <= chiffre_neuf)
												{
													while (c <= chiffre_neuf)
														{		
															while (b <= chiffre_neuf)
																{
																	while (a <= chiffre_neuf)
																		{
								
																			if(n >= 9)
																				write(1, &i, 1);
																			if(n >= 8)
																				write(1, &h, 1);
																			if(n >= 7)
																				write(1, &g, 1);
																			if(n >= 6)
																				write(1, &f, 1);
																			if(n >= 5)
																				write(1, &e, 1);
																			if(n >= 4)
																				write(1, &d, 1);
																			if(n >= 3)
																				write(1, &c, 1);
																			if(n >= 2)
																				write(1, &b, 1);
																			if(n >= 1)
																				write(1, &a, 1);
																			write(1, ",", 1);
																			write(1, " ", 1);
																			a++;
																		}
																	b++;
																	a = (b + 1);
																}
															c++;
															b = c + 1;
															a = b + 1;
														}
													d++;
													c = d + 1;
													b = c + 1;
													a = b + 1;
												}
											e++;
											d = e + 1;
											c = d + 1;
											b = c + 1;
											a = b + 1;
										}
									f++;
									e = f + 1;
									d = e + 1;
									c = d + 1;
									b = c + 1;
									a = b + 1;
								}
							g++;
							f = g + 1;
							e = f + 1;
							d = e + 1;
							c = d + 1;
							b = c + 1;
							a = b + 1;
						}
					h++;
					g = h + 1;
					f = g + 1;
					e = f + 1;
					d = e + 1;
					c = d + 1;
					b = c + 1;
					a = b + 1;
				}
			i++;
			h = i + 1;
			g = h + 1;
			f = g + 1;
			e = f + 1;
			d = e + 1;
			c = d + 1;
			b = c + 1;
			a = b + 1;
		}
	return ;
}

int	main(int ac, char **av)
{
	ft_print_combn(ac);
}
