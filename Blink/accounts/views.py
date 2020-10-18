from django.shortcuts import render
from django.views.generic import CreateView
from django.urls import reverse_lazy
from . import forms

class SignUp(CreateView):
    form_class = forms.UserCreateForm
    success_url = reverse_lazy('login')
    template_name = 'accounts/signup.html'