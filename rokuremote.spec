Name: rokuremote		
Version: 0.6
Release:	2%{?dist}
Summary: A Remote for your Roku	

Group: Multimedia
License: WTFPL
Source0: rokuremote.tar.bz2	

%description
A simple Roku Remote in Glade and C 
%prep
%setup -q

%build
gcc -o rokuremote rokuremote.c $(pkg-config --cflags --libs gtk+-3.0 gmodule-2.0)
gzip rokuremote.1

%install
install -d -m0755 %{buildroot}/%{_datadir}/%{name}
install -d -m0755 %{buildroot}/usr/bin
install -d -m0755 %{buildroot}/%{_datadir}/applications/
install -d -m0755 %{buildroot}/%{_datadir}/man/man1
cp rokuremote.glade %{buildroot}/%{_datadir}/%{name} 
cp rokuremote.c %{buildroot}/%{_datadir}/%{name}
cp rokuremote %{buildroot}/usr/bin
cp rokuremote.1.gz %{buildroot}/%{_datadir}/man/man1
chmod +x %{buildroot}/usr/bin/rokuremote
cp rokuremote.desktop %{buildroot}/%{_datadir}/applications/
%files
/usr/bin/rokuremote
%{_datadir}/rokuremote/rokuremote.glade
%{_datadir}/applications/rokuremote.desktop
%doc %{_datadir}/man/man1/rokuremote.1.gz
%doc %{_datadir}/rokuremote/rokuremote.c
%changelog
* Sun Jul 08 2012 jason@montleon.com 0.5-1
- Add keyboard, man page, and hot keys
* Sat Jul 07 2012 jason@montleon.com 0.1-1
- Initlal Build
