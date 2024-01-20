#include <stdio.h>
int snapshot_cpu_lpi_us(void)
{
    FILE *fp;
    int retval;
    fp = freopen("/sys / devices / system / cpu / cpuidle /low_power_idle_cpu_residency_us", "r", stdin);
    long long int cpuidle_cur_cpu_lpi_us;
    retval = fscanf(fp, "% lld", &cpuidle_cur_cpu_lpi_us);
    if (retval != 1)
    {
        fprintf(stderr, "Disabling Low Power Idle CPU output\n");
        //BIC_NOT_PRESENT(BIC_CPU_LPI);
        return -1;
    }
    fclose(fp);
    return 0;
}
int main()
{
}