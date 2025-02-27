/*@ 
    requires \true;
    assigns \nothing;
    ensures \result == 1 || \result == 0;
    ensures ('0' <= ch <= '9') ==> \result == 1;
    ensures ('a' <= ch <= 'z') ==> \result == 1;
    ensures ('A' <= ch <= 'Z') ==> \result == 1;
    ensures !(('0' <= ch <= '9') || ('a' <= ch <= 'z') || ('A' <= ch <= 'Z')) ==> \result == 0;
*/
int is_alphanumeric(char ch)
{
    return (ch >= '0' && ch <= '9') 
        || (ch >= 'a' && ch <= 'z') 
        || (ch >= 'A' && ch <= 'Z');
}

int r;
/*@ assigns r; */
void main()
{
    r = is_alphanumeric('0');
    //@ assert r;

    r = is_alphanumeric('x');
    //@ assert r;

    r = is_alphanumeric(' ');
    //@ assert !r;
}