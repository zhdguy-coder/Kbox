#!/usr/bin/env python
# coding: utf-8
"""
Copyright Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.

Cherker is to check the system and make sure everything is OK.

check: check system status and container status.

recover: check and try to recover system status and container status.
"""

from kbox_maintainer.checker.api import check
from kbox_maintainer.checker.api import recover

__all__ = ["check", "recover"]