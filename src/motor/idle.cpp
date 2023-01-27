
// make sure motor outputs zero
bool outputZero() {
    if(getThrottleIn() == 0) {
        return true;
    } else {
        return false;
    }
}
