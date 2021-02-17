/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-15     Meco Man     first version
 */

#include <rtthread.h>
#include <stdlib.h>

void __rt_libc_exit(int status)
{
    rt_thread_t self = rt_thread_self();

#ifdef RT_USING_MODULE
    if (dlmodule_self())
    {
        dlmodule_exit(status);
    }
#endif

    if (self != RT_NULL)
    {
        if(status == EXIT_FAILURE) /* abort() */
        {
            rt_kprintf("thread:%s abort!\n", self->name);
        }
        else /* exit() */
        {
            rt_kprintf("thread:%s exit:%d!\n", self->name, status);
        }
        rt_thread_suspend(self);
        rt_schedule();
    }
}

void __rt_libc_abort(void)
{
    __rt_libc_exit(EXIT_FAILURE);
}

int __rt_libc_system(const char *string)
{
    /* TODO */
    return 0;
}
