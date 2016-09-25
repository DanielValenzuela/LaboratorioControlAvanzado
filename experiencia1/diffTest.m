%diff test

foo_t = 1:0.5:10;
foo_datos = foo_t.^2;
d_foo = diff(foo_datos);
d_foo=[d_foo d_foo(length(d_foo))];
d_foo_dt = d_foo./(foo_t(2)-foo_t(1));
d_foo_dt_exact = 2*foo_t;
%subplot(2,1,1)
hold on
plot(foo_t,foo_datos,'bo-')
%subplot(2,1,2)
plot(foo_t,d_foo_dt,'ro-')
plot(foo_t,d_foo_dt_exact,'go-')
hold off