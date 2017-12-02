dd low = -2e9, high = 2e9;
    for(i = 0; i < 500; i++)
    {
        m1 = (low*2+high) / 3;
        m2 = (low+high*2) / 3;
        double a = check(m1);
        double b = check(m2);
        if(a > b)
            low = m1;
        else
            high = m2;
    }
