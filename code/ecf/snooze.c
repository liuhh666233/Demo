unsigned int snooze(unsigned int secs){
    unsigned int  rc = sleep(secs);
    printf("Slept for %d of %d s. \n", secs - rc, rc);
    return rc;
}