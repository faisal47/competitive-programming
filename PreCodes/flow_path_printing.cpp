for (int i = 0; i < sz(mf->G); i++)
        for (int j = 0; j < sz(mf->G[i]); j++)
            if (mf->G[i][j].flow>0ll)
            {
                an=mf->G[i][j].from;
                bn=mf->G[i][j].to;
                nf=(int)mf->G[i][j].flow;
            }
