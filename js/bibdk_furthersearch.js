(function ($) {
    Drupal.behaviors.cart = {
        attach:function (context) {
            $('.hest-knap', context).click(function(){
                console.log('hest');
            });
        }
    };
}(jQuery));
