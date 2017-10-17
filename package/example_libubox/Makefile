#
# Copyright (C) 2006-2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=example_libubox
PKG_RELEASE:=1

PKG_LICENSE:=GPL-2.0+
PKG_LICENSE_FILES:=

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
#  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libubox
  TITLE:=Demo for libubox
endef

define Package/$(PKG_NAME)/description
 This package contains some demo for libubox.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

TARGET_CFLAGS += -DULOOP_PROCESS

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/example_libubox $(1)/usr/sbin/
	$(LN) example_libubox $(1)/usr/sbin/uloop_process
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
