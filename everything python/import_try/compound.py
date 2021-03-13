def comp_interest(p, r, t):
    Amount = p * (pow((1+r/100), t))
    Comp_I = Amount - p
    return Comp_I
