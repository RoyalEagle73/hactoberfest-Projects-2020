from django.urls import path

from .views import PostListAPIView, PostDetailAPIView, PostDeleteAPIView, PostUpdateAPIView, PostCreateAPIView

urlpatterns = [
    path('', PostListAPIView.as_view()),
    path('create/', PostCreateAPIView.as_view()),
    path('<slug>/', PostDetailAPIView.as_view()),
    path('<slug>/del/', PostDeleteAPIView.as_view()),
    path('<slug>/edit/', PostUpdateAPIView.as_view()),
]
