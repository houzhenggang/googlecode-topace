%define  RELEASE 1
%define  rel     %{?CUSTOM_RELEASE} %{!?CUSTOM_RELEASE:%RELEASE}

%define lib_name tvmet

Name: tvmet
Version: 1.7.2
Release: %rel

Summary: Tiny Vector Matrix library using Expression Templates
Copyright: LGPL
Group: Development/Libraries
Vendor: The TVMET Project
Packager: Olaf Petzold
Url: http://tvmet.sourceforge.net/

Source: ftp://download.sourceforge.net/pub/sourceforge/tvmet/%name-%version.tar.gz

Prefix: %_prefix
BuildRoot: %_tmppath/%name-%version-root

%description
Tiny Template Matrix Library is an expression template matrix and vector
library for fast calculations in C++. This make it fast for small (tiny)
linear algebraic systems.

%prep
rm -rf $RPM_BUILD_ROOT

%setup
./configure --prefix=%{prefix} --enable-docs --enable-optimize

%build
make

%install
rm -rf $RPM_BUILD_ROOT
make prefix=$RPM_BUILD_ROOT%{prefix} install

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,755)
%doc AUTHORS COPYING LICENSE INSTALL NEWS README THANKS ChangeLog doc/html/*
%attr(755,root,root) %prefix/bin/tvmet-config
%prefix/include/tvmet/*
%prefix/man/*
%prefix/share/aclocal/
