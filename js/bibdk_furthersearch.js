(function ($) {
    Drupal.doSearch = function(element){
        var tableClass = '.further-search-table-' + element.attr('data-id');
        var table = $(tableClass);
        var url = '((';
        $(tableClass + ' input[type=checkbox]').each(function(){
            if(this.checked){
                //TODO sorting based on type, element, fiction - clarify sorting methods with MAR
                console.log('checked');
                console.log($(this).attr('data-code'));
                url +=  $(this).attr('data-code');
                url += '&'
            } else {
                console.log('not checked');
            }
        });
        url += '))';
        console.log('end');
        console.log(url);
    };

    Drupal.behaviors.furthersearch = {
        attach:function (context) {
            $('.further-search-btn', context).click(function(){
                Drupal.doSearch($(this));
            });
        }
    };
}(jQuery));
