If asked on all corners no water present follow this for nonsafe condition
bool isSafe(int i,int j,int p,int q,int r,int s){
if(p==0&&q==0)
return false;
if(i+p>=0 && i+p<r && j+q >=0 && j+q <s)
return true;
return false;
}
Otherwise if asked for only 4 direction then follow this
if((p==0&&q==0) && (p==-1&&q==-1) && (p==-1&&q==1) && (p==1&&q==-1) && (p==1&&q==1))
return false;
if(i+p>=0 && i+p<r && j+q >=0 && j+q <s)
return true;
return false;
}