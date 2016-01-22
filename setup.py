#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @Author: zhangfang
# @Email:  thuzhf@gmail.com
# @Date:   2016-01-22 11:55:51
# @Last Modified by:   zhangfang
# @Last Modified time: 2016-01-22 13:09:38

from __future__ import print_function,division,unicode_literals,absolute_import
import sys,os,re,json,gzip,math,time,datetime,functools,contextlib,itertools
import multiprocessing as mp
import subprocess as sp
if sys.version_info < (3,): # version 2.x
    range2 = range
    range = xrange
    import ConfigParser as configparser
    import cPickle as pickle
else:
    import configparser
    import pickle

def main():
    if len(sys.argv) != 2:
        print('Usage: ./setup.py dir_name')
    dir_name = sys.argv[1]
    question_name = dir_name.split('_')[-1]
    sp.call(['mkdir', dir_name])
    sp.call(['cp', 'main.cc', 'xxx.hh', 'Makefile', dir_name])
    sp.call(['mv', '{:s}/xxx.hh'.format(dir_name), '{:s}/{:s}.hh'.format(dir_name, question_name)])
    sp.call(['mkdir', '{:s}/obj'.format(dir_name)])
    pass

if __name__ == '__main__':
    start_t = time.time()
    main()
    end_t = time.time()
    t = end_t - start_t
    print('Time elapsed: {:.4f} minutes'.format(t / 60.))
